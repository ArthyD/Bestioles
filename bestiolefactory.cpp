#include "BestioleFactory.h"
#include "BestiolePeureuse.h"
#include "BestiolePrevoyante.h"
#include "BestioleGregaire.h"
#include "BestioleKamikaze.h"
#include <stdlib.h>

Bestiole* BestioleFactory::creationBestiole(bool persoMult, int type, bool aOreille, bool aYeux, bool aCamouflage, bool aCarapace, bool aNageoires){
    if (aOreille){
        double distanceOreille = rand() % (distanceOreilleMax - distanceOreilleMin + 1);
        double capaciteOreille = rand() % (capaciteOreilleMax - capaciteOreilleMin + 1);
    } else {
        double distanceOreille = 0;
        double capaciteOreille = 0;
    }
    
    if (aYeux) {
        double champOeil = rand() % (champoOeilMax - champOeilMin + 1);
        double distanceOeil = rand() % (distanceOeilMax - distanceOeilMin + 1);
        double capaciteOeil = rand() % (capaciteOeilMax - capaciteOeilMin + 1);
    } else {
        double champOeil = 0;
        double distanceOeil = 0;
        double capaciteOeil = 0;
    }
    
    if (aCamouflage){
        double coeffCamouflage = rand() % (coeffCamouflageMax - coeffCamouflageMin + 1);
    } else {
        double coeffCamouflage = 0;
    }
    
    if (aCarapace){
        double coeffCarapace = rand() % coeffCarapaceMax;
        double coeffDebuffCarapace = rand() % coeffDebuffCarapaceMax;
    } else {
        double coeffCarapace = 0;
        double coeffDebuffCarapace = 0;
    }
    
    if (aNageoires){
        double coeffNageoire = rand() % coeffNageoire;
    } else {
        double coeffNageoire = 1;
    }
    
    double age = rand() % (agemax + 1);
    double taille = rand() % (taillemax + 1);
    //création de la bestiole choisie via le type
    if (type==1){
        return new BestioleKamikaze(persoMult, age, champOeil, distanceOeil, distanceOreille, capaciteOeil, capaciteOreille, coeffCamouflage, coeffCarapace, coeffNageoire);
    } if (type ==2){
        return new BestioleGregaire(persoMult, age, champOeil, distanceOeil, distanceOreille, capaciteOeil, capaciteOreille, coeffCamouflage, coeffCarapace, coeffNageoire);
    } if (type ==3){
        return new BestiolePrevoyante(persoMult, age, champOeil, distanceOeil, distanceOreille, capaciteOeil, capaciteOreille, coeffCamouflage, coeffCarapace, coeffNageoire);
    } if (type ==4) {
        int agoraphobie = rand() % (agoramax - agoramin +1);
        return new BestiolePeureuse(persoMult, age, champOeil, distanceOeil, distanceOreille, capaciteOeil, capaciteOreille, coeffCamouflage, coeffCarapace, coeffNageoire, agoraphobie);
    } else {
        return NULL;
    }
}