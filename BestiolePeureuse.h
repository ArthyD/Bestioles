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
        ~BestiolePeureuse( void );
};

#endif