#ifndef _bestioleprevoyante_
#define _bestioleprevoyante_
#include "bestiole.h"
#include <vector>

class bestiolePrevoyante : public bestiole {        
public :        
  void update(vector<bestiole*> vectorBestioleProche);        
};
#endif