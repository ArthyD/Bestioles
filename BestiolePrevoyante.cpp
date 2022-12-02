#include "BestiolePrevoyante.h"
#include <cmath>

BestiolePrevoyante::BestiolePrevoyante(void)
{

   identite = ++next;

   cout << "Naissance Bestiole (" << identite << ") prevoyante" << endl;

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

BestiolePrevoyante::BestiolePrevoyante(bool pM, double t, int a, double champo, double disto, double distOr, double capaOeil, double capaOreille, double coeffCamou, double coeffCarap, double coeffNag){
   
   identite = ++next;
   cout << "Naissance Bestiole (" << identite << ") prevoyante" << endl;

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
    
    std::cout << "Create bestiole prevoyante" << std::endl;
} 

BestiolePrevoyante::~BestiolePrevoyante(){
};

void BestiolePrevoyante::update(vector<Bestiole*>& vectorBestioleProche){

    vector<double> mauvaisesOrientations;

    for (auto & bestioleProche : vectorBestioleProche){
        mauvaisesOrientations.push_back(bestioleProche->getOrientation());
    }

    std::sort (mauvaisesOrientations.begin(), mauvaisesOrientations.end());
    double meilleurEcart = 0;
    double meilleureOrientation = orientation;
    double ecart;
    for (std::vector<double>::iterator it = mauvaisesOrientations.begin() ; it!= mauvaisesOrientations.end(); ++it) {
        ecart = *(it+1) - *it;

        if (ecart > meilleurEcart) {
            meilleurEcart = ecart;
            meilleureOrientation = (*(it) + *(it+1)) / 2;
        }
    }
    if (2*M_PI + *(mauvaisesOrientations.begin()) - *(mauvaisesOrientations.end()) > meilleurEcart) {
        meilleureOrientation = ((*(mauvaisesOrientations.begin()) + *(mauvaisesOrientations.end()) ) / 2) + M_PI;
    }
    orientation = meilleureOrientation;
}