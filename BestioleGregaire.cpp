#include "BestioleGregaire.h"

BestioleGregaire::BestioleGregaire(void){}

BestioleGregaire::BestioleGregaire(bool pM, double t, int a, double champo, double disto, double distOr, double capaOeil, double capaOreille, double coeffCamou, double coeffCarap, double coeffNag){} 

BestioleGregaire::~BestioleGregaire(){};

void BestioleGregaire::update(vector<Bestiole*>& vectorBestioleProche){
    double moyenne = 0;
    if(vectorBestioleProche.size() !=0){
        for (std::vector<Bestiole*>::iterator it = vectorBestioleProche.begin() ; it != vectorBestioleProche.end() ; it++){
                moyenne += (*it)->getOrientation();
        }
        moyenne = moyenne/vectorBestioleProche.size();
        orientation = moyenne;
    }
}