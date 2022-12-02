#include "BestiolePrevoyante.h"

void BestiolePrevoyante::update(vector<Bestiole*> vectorBestioleProche){

    vector<double> mauvaisesOrientations;

    for (auto & bestioleProche : vectorBestioleProche){
        mauvaisesOrientations.push_back(bestioleProche->getOrientation());
    }
    std::sort (mauvaisesOrientations.begin(), mauvaisesOrientations.end());
    double meilleurEcart = 0;
    double meilleureOrientation = getOrientation();
    for (std::vector<double>::iterator it = mauvaisesOrientations.begin() ; it!= mauvaisesOrientations.end() - 1 ; ++it) {
        double ecart = *(it+1) - *it;
        if (ecart > meilleurEcart) {
            meilleurEcart = ecart;
            meilleureOrientation = (*(it) + *(it+1)) / 2;
        }
    }
    setOrientation(meilleureOrientation);
}