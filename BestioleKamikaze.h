#ifndef _bestioleKamikaze_
#define _bestioleKamikaze_
#include "bestiole.h"
#include <vector>

class bestioleKamikaze : public bestiole {        
public :        
  void update(vector<bestiole*> vectorBestioleProche);        
};
#endif