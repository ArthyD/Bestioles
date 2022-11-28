#ifndef _bestioleprevoyante_
#define _bestioleprevoyante_
#include "Bestiole.h"
#include <vector>

class BestiolePrevoyante : public Bestiole {        
public :  
  BestiolePrevoyante(bool persoMult, int age, double champOeil, double distanceOeil, double distanceOreille, double capaciteOeil, double capaciteOreille, double coeffCamouflage, double coeffCarapace, double coeffNageoire);      
  void update(vector<Bestiole*> vectorBestioleProche);        
};
#endif