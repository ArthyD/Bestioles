#include "Milieu.h"

#include <cstdlib>
#include <ctime>
#include <random>
#include <iostream>

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}

void Milieu::step( void ){
   
   phaseDetection();
   phaseAction();
   //PhaseEnvironnement();
   //naissanceAlea();

}

void Milieu::phaseEnvironnement( void ){

}

int Milieu::randomPerso(){
   double tirageAlea = static_cast<double>( std::rand()/RAND_MAX);
   if (tirageAlea < pourcentageGregaire){
      return 2;
   if (tirageAlea < pourcentageGregaire + pourcentagePeureuse)
   {
      return 4;
   }
      if (tirageAlea < pourcentageGregaire + pourcentagePeureuse + pourcentageKamikaze)
   {
      return 1;
   }
   return 3;
   }

}

void Milieu::naissanceAlea( void ){

   double tirageAlea = static_cast<double>( std::rand()/RAND_MAX);
   BestioleFactory factory;
   if (tirageAlea < probaNaissance)
   {
      bool persoMult,type,aOreille,aYeux,aCamouflage,aCarapace,aNageoires;
      persoMult = std::rand()%2;
      type = std::rand()%2;
      aYeux = std::rand()%2;
      aCamouflage = std::rand()%2;
      aCarapace = std::rand()%2;
      aNageoires = std::rand()%2;
      int persoAlea = randomPerso();
      Bestiole* best = factory.creationBestiole(persoMult, persoAlea, aOreille, aYeux, aCamouflage, aCamouflage, aNageoires);
      addMember(best);
   }
}

void Milieu::phaseDetection ( void ){
   std::vector<Bestiole*> bestiolesAlentours;
   for ( std::list<Bestiole*>::iterator it1 = listeBestioles.begin() ; it1 != listeBestioles.end() ; it1++ )
   {
      for ( std::list<Bestiole*>::iterator it2 = listeBestioles.begin() ; it2 != listeBestioles.end() ; it2++ )
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
   for ( std::list<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {

      (*it)->action( *this );
      (*it)->draw( *this );

   } 

}


int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::list<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == **it) && b.jeTeVois(**it) )
         ++nb;

   return nb;

}
