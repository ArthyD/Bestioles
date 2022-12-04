#include "BestiolePrevoyante.h"
#include <cmath>

BestiolePrevoyante::BestiolePrevoyante(void){}

BestiolePrevoyante::BestiolePrevoyante(bool pM, double t, int a, double champo, double disto, double distOr, double capaOeil, double capaOreille, double coeffCamou, double coeffCarap, double coeffDebuffCarap, double coeffNag){
        identite = ++next;
   cout << "Naissance Bestiole (" << identite << ") " << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE * (coeffNageoire / coeffDebuffCarapace);

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

   persoMult = pM;
   taille = t;
   anneesRestantes = a;

   champOeil = champo;
   champOreille = 2*M_PI;
   distanceOeil = disto;
   distanceOreille = distOr;
   capaciteOeil = capaOeil;
   capaciteOreille = capaOreille;
   coeffCamouflage = coeffCamou;
   coeffCarapace = coeffCarap;
   coeffDebuffCarapace = coeffDebuffCarap;
   coeffNageoire = coeffNag;
} 

BestiolePrevoyante::~BestiolePrevoyante(){};

void BestiolePrevoyante::update(vector<std::shared_ptr<Bestiole>>& vectorBestioleProche){

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
    if(mauvaisesOrientations.size() != 0){
        if (2*M_PI + *(mauvaisesOrientations.begin()) - *(mauvaisesOrientations.end()) > meilleurEcart) {
            meilleureOrientation = ((*(mauvaisesOrientations.begin()) + *(mauvaisesOrientations.end()) ) / 2) + M_PI;
        }
    }

    orientation = meilleureOrientation;
}