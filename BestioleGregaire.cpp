#include "BestioleGregaire.h"
#include <iostream>
BestioleGregaire::BestioleGregaire(bool persoMult, int age, double champOeil, double distanceOeil, double distanceOreille, double capaciteOeil, double capaciteOreille, double coeffCamouflage, double coeffCarapace, double coeffNageoire){
    std::cout << "Create bestiole gregaire" << std::endl;
}    
void BestioleGregaire::update(vector<Bestiole*> vectorBestioleProche){
    double moyenne = 0;
    for (auto & bestioleProche : vectorBestioleProche){
            moyenne += bestioleProche->getOrientation();
        }
    moyenne += moyenne/vectorBestioleProche.size();
    setOrientation(moyenne);
}