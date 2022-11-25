#include "BestioleGregaire.h"

void bestioleGregaire::update(vector<bestiole*> vectorBestioleProche){
    double moyenne = 0;
    for (auto & bestioleProche : vectorBestioleProche){
            moyenne += bestioleProche.getDirection();
        }
    moyenne += moyenne/vectorBestioleProche.size();
    this.setDirection(moyenne);
}