#include "BestiolePeureuse.h"
#include <cmath>

// const double      Bestiole::AFF_SIZE = 8.;
// const double      Bestiole::MAX_VITESSE = 8.;
// const double      Bestiole::LIMITE_VUE = 250.;

// int               Bestiole::next = 0;


BestiolePeureuse::BestiolePeureuse(void)
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

   agoraphobe = 2;
   fuite = false;
   compteur = 1000;
}
BestiolePeureuse::BestiolePeureuse(bool persoMult, int age, double champOeil, double distanceOeil, double distanceOreille, double capaciteOeil, double capaciteOreille, double coeffCamouflage, double coeffCarapace, double coeffNageoire, int agoraphobe){
    std::cout << "Create bestiole peureuse" << std::endl;
}  

BestiolePeureuse::~BestiolePeureuse(){};

void BestiolePeureuse::update(std::vector<Bestiole>& vectorBestioleProche){
    if (fuite){
        if (compteur == 0) {
            fuite = false;
            vitesse = vitesse / 2;
        } else {
            compteur -=1;
        }
    } else if(vectorBestioleProche.size() >= agoraphobe){
        double pi = M_PI;
        fuite = true;
        if (orientation < pi){
            orientation += pi;
        } else {
            orientation -= pi;
        }
        vitesse = vitesse * 2;
        compteur = 1000;
    }
}