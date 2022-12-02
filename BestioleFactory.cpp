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
    return static_cast<double>( rand() )/RAND_MAX*max;
}

Bestiole* BestioleFactory::creationBestiole(bool persoMult, int type, bool aOreille, bool aYeux, bool aCamouflage, bool aCarapace, bool aNageoires){
    
    if (aOreille){
        distanceOreille = randomDouble(distanceOreilleMin,distanceOreilleMax); 
        capaciteOreille = randomDouble(capaciteOreilleMin,capaciteOreilleMax);
    } else {
        distanceOreille = 0.0;
        capaciteOreille = 0.0;
    }
    
    if (aYeux) {
        champOeil = randomDouble(champOeilMin,champOeilMax); 
        distanceOeil = randomDouble(distanceOeilMin,distanceOeilMax); 
        capaciteOeil = randomDouble(capaciteOeilMin,capaciteOeilMax); 
    } else {
        champOeil = 0.0;
        distanceOeil = 0.0;
        capaciteOeil = 0.0;
    }
       
    
    if (aCamouflage){
        coeffCamouflage = randomDouble(coeffCamouflageMin,coeffCamouflageMax); 
    } else {
        coeffCamouflage = 0.0;
    }
    
    if (aCarapace){
        coeffCarapace = randomDouble(0.0,coeffCarapaceMax); 
        coeffDebuffCarapace = randomDouble(0.0, coeffDebuffCarapace);
    } else {
        coeffCarapace = 0.0;
        coeffDebuffCarapace = 0.0;
    }
    
    if (aNageoires){
        coeffNageoire = randomDouble(1.0,100.0);
    } else {
        coeffNageoire = 1.0;
    }
    
    int age = rand() % (agemax + 1);
    double taille = randomDouble(1.0,taillemax);
    //création de la bestiole choisie via le type
    if (type==1){
        return new BestioleKamikaze(persoMult, taille, age, champOeil, distanceOeil, distanceOreille, capaciteOeil, capaciteOreille, coeffCamouflage, coeffCarapace, coeffNageoire);
    } 
    if (type ==2){
        return new BestioleGregaire(persoMult, taille, age, champOeil, distanceOeil, distanceOreille, capaciteOeil, capaciteOreille, coeffCamouflage, coeffCarapace, coeffNageoire);
    } 
    else if (type ==3){
        return new BestiolePrevoyante(persoMult, taille, age, champOeil, distanceOeil, distanceOreille, capaciteOeil, capaciteOreille, coeffCamouflage, coeffCarapace, coeffNageoire);
    } 
    if (type ==4) {
        int agoraphobie = agoraMin + rand() % (agoraMax - agoraMin +1);
        BestiolePeureuse* b = new BestiolePeureuse(persoMult, taille, age, champOeil, distanceOeil, distanceOreille, capaciteOeil, capaciteOreille, coeffCamouflage, coeffCarapace, coeffNageoire);
        return b;
    } else {
        return NULL;
    }
}



