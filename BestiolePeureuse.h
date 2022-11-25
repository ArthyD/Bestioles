#ifndef _bestiolepeureuse_
#define _bestiolepeureuse_
#include "Bestiole.h"
#include <vector>

class bestiolePeureuse : public bestiole {
    private :
        int agoraphobe;
        int compteur;
        bool fuite;
    public :
        void update(vector<bestiole*> vectorBestioleProche);
};

#endif