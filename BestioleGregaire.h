#ifndef _bestiolegregaire_
#define _bestiolegregaire_
#include "bestiole.h"
#include <vector>

class bestioleGregaire : public bestiole {        
public :        
  void update(vector<bestiole*> vectorBestioleProche);        
};
#endif