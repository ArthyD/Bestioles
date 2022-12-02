#ifndef _bestioleprevoyante_
#define _bestioleprevoyante_
#include "Bestiole.h"
#include <vector>

class BestiolePrevoyante : public Bestiole {        
public :  
  BestiolePrevoyante(bool pM, double t, int a, double champo, double disto, double distOr, double capaOeil, double capaOreille, double coeffCamou, double coeffCarap, double coeffNag);      
  void update(vector<Bestiole*>& vectorBestioleProche);   
  BestiolePrevoyante(void );
  ~BestiolePrevoyante( void );          
};
#endif