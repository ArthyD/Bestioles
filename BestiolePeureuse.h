#ifndef _bestiolepeureuse_
#define _bestiolepeureuse_
#include "Bestiole.h"
#include <vector>
#include <memory>

class BestiolePeureuse : public Bestiole {
    private :
        long unsigned int agoraphobe = 1;
        int compteur = 100;
        bool fuite = false;
    public :
        void update(std::vector<std::shared_ptr<Bestiole>>& vectorBestioleProche);
        BestiolePeureuse(bool persoMult, double t, int age, double champOeil, double distanceOeil, double distanceOreille, double capaciteOeil, double capaciteOreille, double coeffCamouflage, double coeffCarapace, double coeffDebuffCarap, double coeffNageoire);
        BestiolePeureuse(void );
        ~BestiolePeureuse(void);
        void setAgoraphobie(int ago);
        bool getFuite();
};

#endif