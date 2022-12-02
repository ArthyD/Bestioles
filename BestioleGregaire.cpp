#include "BestioleGregaire.h"

BestioleGregaire::BestioleGregaire(void)
{

   identite = ++next;

   cout << "Naissance Bestiole (" << identite << ") peureuse" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

   persoMult = false ;
   taille = 1 ;

   champOeil =0;
   champOreille =0;
   distanceOeil = 0;
   distanceOreille = 0;
   capaciteOeil = 0;
   capaciteOreille = 0;
   coeffCamouflage = 0;
   coeffCarapace = 1;
   coeffNageoire = 1;
}

BestioleGregaire::BestioleGregaire(bool pM, double t, int a, double champo, double disto, double distOr, double capaOeil, double capaOreille, double coeffCamou, double coeffCarap, double coeffNag){
   
   identite = ++next;
   cout << "Naissance Bestiole (" << identite << ") peureuse" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

   persoMult = pM;
   taille = t;

   champOeil = champo;
   champOreille = 2*M_PI;
   distanceOeil = disto;
   distanceOreille = distOr;
   capaciteOeil = capaOeil;
   capaciteOreille = capaOreille;
   coeffCamouflage = coeffCamou;
   coeffCarapace = coeffCarap;
   coeffNageoire = coeffNag;
    
    std::cout << "Create bestiole gregaire" << std::endl;
} 

BestioleGregaire::~BestioleGregaire(){
};

void BestioleGregaire::update(vector<Bestiole*>& vectorBestioleProche){
    double moyenne = 0;
    if(vectorBestioleProche.size() !=0){
        for (std::vector<Bestiole*>::iterator it = vectorBestioleProche.begin() ; it != vectorBestioleProche.end() ; it++){
                moyenne += (*it)->getOrientation();
        }
        moyenne = moyenne/vectorBestioleProche.size();
        orientation = moyenne;
    }
}