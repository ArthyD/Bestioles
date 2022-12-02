#ifndef _bestiolegregaire_
#define _bestiolegregaire_
#include "Bestiole.h"
#include <vector>

class BestioleGregaire : public Bestiole {        
public :  
  BestioleGregaire(bool pM, double t, int a, double champo, double disto, double distOr, double capaOeil, double capaOreille, double coeffCamou, double coeffCarap, double coeffDebuffCarap, double coeffNag);      
  void update(vector<Bestiole*>& vectorBestioleProche);   
  BestioleGregaire(void );
  ~BestioleGregaire( void );     
};
#endif