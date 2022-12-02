#include "BestiolePeureuse.h"
#include <cmath>

BestiolePeureuse::BestiolePeureuse(void)
{
   agoraphobe = 2;
   fuite = false;
   compteur = 1000;
}

BestiolePeureuse::BestiolePeureuse(bool pM, double t, int a, double champo, double disto, double distOr, double capaOeil, double capaOreille, double coeffCamou, double coeffCarap, double coeffDebuffCarap, double coeffNag){
   agoraphobe = 2;
   fuite = false;
   compteur = 1000;
} 

void BestiolePeureuse::setAgoraphobie(int agor){
    agoraphobe = agor;
}



void BestiolePeureuse::update(std::vector<Bestiole*>& vectorBestioleProche){
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