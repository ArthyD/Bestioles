#ifndef _bestioleKamikaze_
#define _bestioleKamikaze_
#include "Bestiole.h"
#include <vector>
#include <memory>

class BestioleKamikaze : public Bestiole {        
public :
  BestioleKamikaze(bool pM, double t, int a, double champo, double disto, double distOr, double capaOeil, double capaOreille, double coeffCamou, double coeffCarap, double coeffDebuffCarap, double coeffNag);      
  void update(vector<std::shared_ptr<Bestiole>>& vectorBestioleProche);   
  BestioleKamikaze(void );
  ~BestioleKamikaze( void );           
};
#endif