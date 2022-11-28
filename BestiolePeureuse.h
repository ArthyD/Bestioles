#ifndef _bestiolepeureuse_
#define _bestiolepeureuse_
#include "Bestiole.h"
#include <vector>

class BestiolePeureuse : public Bestiole {
    private :
        long unsigned int agoraphobe;
        int compteur;
        bool fuite;
    public :
        void update(std::vector<Bestiole>& vectorBestioleProche);
        BestiolePeureuse(void );
        BestiolePeureuse(bool persoMult, int age, double champOeil, double distanceOeil, double distanceOreille, double capaciteOeil, double capaciteOreille, double coeffCamouflage, double coeffCarapace, double coeffNageoire, int agoraphobe);
        ~BestiolePeureuse( void );
};

#endif