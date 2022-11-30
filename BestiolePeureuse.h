#ifndef _bestiolepeureuse_
#define _bestiolepeureuse_
#include "Bestiole.h"
#include <vector>
#include <iostream>

class BestiolePeureuse : public Bestiole {
    private :
        long unsigned int agoraphobe = 1;
        int compteur = 100;
        bool fuite = false;
    public :
        void update(std::vector<Bestiole>& vectorBestioleProche);
        BestiolePeureuse(void );
        ~BestiolePeureuse( void );
};

#endif