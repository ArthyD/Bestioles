#ifndef _bestioleKamikaze_
#define _bestioleKamikaze_
#include "Bestiole.h"
#include <vector>

class BestioleKamikaze : public Bestiole {        
public :
  BestioleKamikaze(bool persoMult, int age, double champOeil, double distanceOeil, double distanceOreille, double capaciteOeil, double capaciteOreille, double coeffCamouflage, double coeffCarapace, double coeffNageoire);       
  void update(vector<Bestiole*> vectorBestioleProche);        
};
#endif