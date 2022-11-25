#include "bestiolegregaire.h"

void bestiolePeureuse::update(vector<bestiole*> vectorBestioleProche){
    double moyenne = 0;
    for (auto & bestioleProche : vectorBestioleProche){
            moyenne += bestioleProche.getDirection();
        }
    moyenne += moyenne/vectorBestioleProche.size();
    this.setDirection(moyenne);
}