#ifndef _bestiolefactory_
#define _bestiolefactory_
#include "Bestiole.h"

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
        double coeffDebuffCarapaceMax;;
        //camouflage;
        double coeffCamouflageMax;
        double coeffCamouflageMin;

        //bestiolepeureuse
        int agoraMin;
        int agoraMax;

        // autre :
        double taillemax;
        int agemax;
        
    public :
    Bestiole* creationBestiole(bool persoMult, int type, bool aOreille, bool aYeux, bool aCamouflage, bool aCarapace, bool aNageoires);
    BestioleFactory();
    ~BestioleFactory();
    double randomDouble(double min, double max);

    
};

#endif