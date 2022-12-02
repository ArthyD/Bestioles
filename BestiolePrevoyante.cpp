#include "BestiolePrevoyante.h"
#include <cmath>

BestiolePrevoyante::BestiolePrevoyante(void){}

BestiolePrevoyante::BestiolePrevoyante(bool pM, double t, int a, double champo, double disto, double distOr, double capaOeil, double capaOreille, double coeffCamou, double coeffCarap, double coeffNag){} 

BestiolePrevoyante::~BestiolePrevoyante(){};

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
    if(mauvaisesOrientations.size() != 0){
        if (2*M_PI + *(mauvaisesOrientations.begin()) - *(mauvaisesOrientations.end()) > meilleurEcart) {
            meilleureOrientation = ((*(mauvaisesOrientations.begin()) + *(mauvaisesOrientations.end()) ) / 2) + M_PI;
        }
    }

    orientation = meilleureOrientation;
}