#include "bestiolepeureuse.h"
#include<cmath>

void bestiolePeureuse::update(vector<bestiole*> vectorBestioleProche){
    if (fuite){
        if (compteur == 0) {
            fuite = false;
            this.setVitesse(this.getVitesse()/2);
        } else {
            compteur -=1;
        }
    } else if(vectorBestioleProche.size()>=agoraphobe){
        if (this.getDirection()< pi){
            this.setDirection(this.getDirection()+pi);
        } else {
            this.setDirection(this.getDirection()-pi);
        }
        this.setVitesse(this.getVitesse()*2);
    }
}