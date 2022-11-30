#ifndef _BESTIOLEFACTORY_
#define _BESTIOLEFACTORY_
#include "Bestiole.h"
#include "BestiolePeureuse.h"

class BestioleFactory {
    private :
        //yeux
        double champOeilMax;
        double champOeilMin;
        double distanceOeilMax;
        double distanceOeilMin;
        double capaciteOeilMax;
        double capaciteOeilMin;
        //oreilles
        double distanceOreilleMin;
        double distanceOreilleMax;
        double capaciteOreilleMax;
        double capaciteOreilleMin;
        //nageoires
        double coeffNageoire = 1;
        //carapace
        double coeffCarapaceMax;
        double coeffDebuffCarapaceMax;;
        //camouflage;
        double coeffCamouflageMax;
        double coeffCamouflageMin;

        //bestiolepeureuse
        int agoraMin = 1;
        int agoraMax = 1;

        // autre :
        double taillemax = 5;
        int agemax;
        
    public :
        Bestiole* creationBestiole(bool persoMult, int type, bool aOreille, bool aYeux, bool aCamouflage, bool aCarapace, bool aNageoires);
        BestioleFactory();
        ~BestioleFactory();
        double randomDouble(double min, double max);
};

#endif