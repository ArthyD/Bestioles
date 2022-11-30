#include "BestioleFactory.h"

#include <stdlib.h>
#include <time.h>


double distanceOreille = 0;
double capaciteOreille = 0;
double champOeil = 0;
double distanceOeil = 0;
double capaciteOeil = 0;
double coeffCamouflage = 0;
double coeffCarapace = 0;
double coeffDebuffCarapace = 0;
double coeffNageoire = 1;

BestioleFactory::BestioleFactory()
{}

BestioleFactory::~BestioleFactory()
{}


double BestioleFactory::randomDouble(double min, double max) {
    //std::srand(std::time(nullptr));
    //return (((double)rand()*(max) / RAND_MAX) - max) *(-1);
    return static_cast<double>( rand() )/RAND_MAX*max;
}

Bestiole* BestioleFactory::creationBestiole(bool persoMult, int type, bool aOreille, bool aYeux, bool aCamouflage, bool aCarapace, bool aNageoires){
    
    if (aOreille){
        distanceOreille = randomDouble(distanceOreilleMin,distanceOreilleMax); 
        capaciteOreille = randomDouble(capaciteOreilleMin,capaciteOreilleMax);
    }
    
    if (aYeux) {
        champOeil = randomDouble(champOeilMin,champOeilMax); 
        distanceOeil = randomDouble(distanceOeilMin,distanceOeilMax); 
        capaciteOeil = randomDouble(capaciteOeilMin,capaciteOeilMax); 
    }
       
    
    if (aCamouflage){
        coeffCamouflage = randomDouble(coeffCamouflageMin,coeffCamouflageMax); 
    }
    
    if (aCarapace){
        coeffCarapace = randomDouble(0.0,coeffCarapaceMax); 
        coeffDebuffCarapace = randomDouble(0.0, coeffDebuffCarapace);
    } 
    
    if (aNageoires){
        coeffNageoire = randomDouble(1.0,100.0);
    } 
    
    int age = rand() % (agemax + 1);
    double taille = randomDouble(1.0,taillemax);
    //création de la bestiole choisie via le type
    // if (type==1){
    //     return new BestioleKamikaze(persoMult, age, champOeil, distanceOeil, distanceOreille, capaciteOeil, capaciteOreille, coeffCamouflage, coeffCarapace, coeffNageoire);
    // } 
    // if (type ==2){
    //     return new BestioleGregaire(persoMult, age, champOeil, distanceOeil, distanceOreille, capaciteOeil, capaciteOreille, coeffCamouflage, coeffCarapace, coeffNageoire);
    // } 
    // else if (type ==3){
    //     return new BestiolePrevoyante(persoMult, age, champOeil, distanceOeil, distanceOreille, capaciteOeil, capaciteOreille, coeffCamouflage, coeffCarapace, coeffNageoire);
    // } 
    if (type ==4) {
        int agoraphobie = rand() % (agoraMax - agoraMin +1);
        return new BestiolePeureuse(persoMult, taille, age, champOeil, distanceOeil, distanceOreille, capaciteOeil, capaciteOreille, coeffCamouflage, coeffCarapace, coeffNageoire, agoraphobie);
    } else {
        return NULL;
    }
}



