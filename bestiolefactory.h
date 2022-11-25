#ifndef _bestiolefactory_
#define _bestiolefactory_
#include "bestiole.h"

class bestioleFactory {
    private :
        //yeux
        double champoOeilMax;
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
        double agoraMin;
        double agoraMax;

        // autre :
        double taillemax;
        double agemax;
        
    public :
    bestiole* creationBestiole(int type, bool aOreille, bool aYeux, bool aCamouflage, bool aCarapace, bool aNageoires);
    bestioleFactory();
    ~bestioleFactory();
};

#endif