#ifndef _BESTIOLEFACTORY_
#define _BESTIOLEFACTORY_
#include "Bestiole.h"
#include "BestiolePeureuse.h"
#include "BestioleGregaire.h"
#include "BestioleKamikaze.h"
#include "BestiolePrevoyante.h"

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
        double coeffNageoire;
        //carapace
        double coeffCarapaceMax;
        double coeffDebuffCarapaceMax;
        //camouflage;
        double coeffCamouflageMin;
        double coeffCamouflageMax;

        //bestiolepeureuse
        int agoraMin = 1;
        int agoraMax = 3;

        // autre :
        double taillemax = 5;
        int agemax;
        
    public :
        Bestiole* creationBestiole(bool persoMult, int type, bool aOreille, bool aYeux, bool aCamouflage, bool aCarapace, bool aNageoires);
        BestioleFactory();
        ~BestioleFactory();
        void readConfig(void);
        double randomDouble(double min, double max);
};

#endif