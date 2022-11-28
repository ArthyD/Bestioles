#include "BestiolePeureuse.h"
#include <cmath>
#include <iostream>
BestiolePeureuse::BestiolePeureuse(bool persoMult, int age, double champOeil, double distanceOeil, double distanceOreille, double capaciteOeil, double capaciteOreille, double coeffCamouflage, double coeffCarapace, double coeffNageoire, int agoraphobe){
    std::cout << "Create bestiole peureuse" << std::endl;
}  
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