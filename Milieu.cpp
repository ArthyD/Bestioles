#include "Milieu.h"

#include <cstdlib>
#include <ctime>
#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{
   readConfig();
   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{
   cout << "dest Milieu" << endl;
}

void Milieu::readConfig(void)
{
   ifstream fichier("./config.txt", ios::in);
   if (fichier)
   {
            std::string ligne;
            std::string champ;
            double valeur;
            for (int i =0;  i < 5; i++)
        {
            getline(fichier, ligne);
            std::size_t pos = ligne.find("=");
            champ = ligne.substr(0,pos);
            valeur = stod(ligne.substr(pos+1));
            if (champ == "Pourcentage Kamikaze") {
             pourcentageKamikaze = valeur;
            }
            if (champ == "Pourcentage Grégaire") {
             pourcentageGregaire = valeur;
            }
            if (champ == "Pourcentage Peureuse") {
             pourcentagePeureuse = valeur;
            }            
            if (champ == "Pourcentage Personnalité Multiple") {
             pourcentagePersoMulti = valeur;
            }
            if (champ == "Pourcentage Prevoyante") {
             pourcentagePrevoyante = valeur;
            }
        }
   }
   else {
      cerr << "Impossible d'ouvrir le fichier de configuration !" << endl;
   }
   fichier.close();
}

void Milieu::step( void ){
   
   phaseDetection();
   phaseAction();
   phaseEnvironnement();
   //naissanceAlea();

}
bool del(std::shared_ptr<Bestiole> b){return b->isDeletedSoon();}
//bool estMorte(std::shared_ptr<Bestiole> b) { b->vieillit(); return (b->getAnneesRestantes() <= 0); }

void Milieu::phaseEnvironnement( void ){
   // Gestion de l'âge
   // Si la bestiole atteint son âge maximal, elle meurt
   //listeBestioles.erase(std::remove_if(listeBestioles.begin(), listeBestioles.end(), estMorte), listeBestioles.end());
   for ( std::list<std::shared_ptr<Bestiole>>::iterator it = listeBestioles.begin() ; 
            it != listeBestioles.end() ; it++ ){
         (*it)->vieillit();
         if((*it)->getAnneesRestantes()<=0){
            (*it)->deleteBestiole();
         }
      }
   //Gestion des collisions
   std::vector<std::shared_ptr<Bestiole>> collisions;
   for ( std::list<std::shared_ptr<Bestiole>>::iterator it1 = listeBestioles.begin() ; 
         it1 != listeBestioles.end() ; it1++ ){
      for ( std::list<std::shared_ptr<Bestiole>>::iterator it2 = listeBestioles.begin() ; 
            it2 != it1 ; it2++ ){
         if ((*it2)->checkCollision((*it1))){
            collisions.push_back(*it1);
            collisions.push_back(*it2);
         }
      }
   }  

   for ( std::vector<std::shared_ptr<Bestiole>>::iterator it1 = collisions.begin() ; 
         it1 != collisions.end() ; it1++ ){
            if((**it1).collision()){
               listeBestioles.remove(*it1);
            }
            else{
               (**it1).rebondit();
            }

         }


   // Changement de personalité des personalités multiples
   for ( std::list<std::shared_ptr<Bestiole>>::iterator it = listeBestioles.begin() ; 
         it != listeBestioles.end() ; it++ ){
      if((*it)->isPersoMult()){
         if(std::rand()%60==0){
            int type = randomPerso();
            BestioleFactory factory;
            std::shared_ptr<Bestiole> best = factory.creationBestiole(true, type, false, false, false, false, false);
            cout << "changement" << endl;
            best->cloneFromBestiole(*it);
            addMember(best);
            (*it)->deleteBestiole();   
         }
      }
   }
   listeBestioles.erase(std::remove_if(listeBestioles.begin(), listeBestioles.end(), del), listeBestioles.end());
}


int Milieu::randomPerso(){
   double tirageAlea = static_cast<double>( std::rand()/RAND_MAX);
   int type = 1;
   if (tirageAlea < pourcentageGregaire){
      type = 2;
   }
   else if (tirageAlea < pourcentageGregaire + pourcentagePeureuse)
   {
      type = 4;
   }
   else if (tirageAlea < pourcentageGregaire + pourcentagePeureuse + pourcentageKamikaze)
   {
      type = 1;
   }
   else {
      type = 3;
   }
   return type;
}

void Milieu::naissanceAlea( void ){

   BestioleFactory factory;
   double tirageAlea = static_cast<double>( std::rand()/RAND_MAX);
   if (tirageAlea < probaNaissance)
   {
      addPersoAlea();
   }
}

void Milieu::addPersoAlea( void ){
   BestioleFactory factory;
   bool persoMult,aOreille,aYeux,aCamouflage,aCarapace,aNageoires;
   persoMult = std::rand()%2;
   aYeux = std::rand()%2;
   aOreille = std::rand()%2;
   aCamouflage = std::rand()%2;
   aCarapace = std::rand()%2;
   aNageoires = std::rand()%2;
   int persoAlea = randomPerso();
   std::shared_ptr<Bestiole> best = factory.creationBestiole(persoMult, persoAlea, aOreille, aYeux, aCamouflage, aCarapace, aNageoires);
   addMember(best);
}


void Milieu::phaseDetection ( void ){
   std::vector<std::shared_ptr<Bestiole>> bestiolesAlentours;
   for ( std::list<std::shared_ptr<Bestiole>>::iterator it1 = listeBestioles.begin() ; it1 != listeBestioles.end() ; it1++ )
   {
      for ( std::list<std::shared_ptr<Bestiole>>::iterator it2 = listeBestioles.begin() ; it2 != listeBestioles.end() ; it2++ )
      {
         if ((*it1)->getIdentite() != (*it2)->getIdentite()) {
            if ( (*it1)->jeTeVois(**it2) ) 
            {
               bestiolesAlentours.push_back(*it2);
            }
            (*it1)->update(bestiolesAlentours);
         }
      }
      bestiolesAlentours.clear();
      }
}

void Milieu::phaseAction( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::list<std::shared_ptr<Bestiole>>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      (*it)->action( *this );
      (*it)->draw( *this );

   } 

}


int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::list<std::shared_ptr<Bestiole>>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == **it) && b.jeTeVois(**it) )
         ++nb;

   return nb;

}

