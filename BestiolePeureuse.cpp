#include "BestiolePeureuse.h"
#include <cmath>

BestiolePeureuse::BestiolePeureuse(){};

BestiolePeureuse::~BestiolePeureuse(){};

void BestiolePeureuse::update(std::vector<Bestiole>& vectorBestioleProche){
    if (fuite){
        if (compteur == 0) {
            fuite = false;
            vitesse = vitesse/2;
        } else {
            compteur -=1;
        }
    } else if(vectorBestioleProche.size() >= agoraphobe){
        double pi = M_PI;
        if (orientation < pi){
            orientation += pi;
        } else {
            orientation -= pi;
        }
        vitesse = vitesse * 2;
    }
}