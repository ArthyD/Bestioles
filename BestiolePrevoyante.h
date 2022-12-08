#ifndef _bestioleprevoyante_
#define _bestioleprevoyante_
#include "Bestiole.h"
#include <vector>
#include <memory>

class BestiolePrevoyante : public Bestiole {        
public :  
  BestiolePrevoyante(bool pM, double t, int a, double champo, double disto, double distOr, double capaOeil, double capaOreille, double coeffCamou, double coeffCarap, double coeffDebuffCarap, double coeffNag);      
  void update(vector<std::shared_ptr<Bestiole>>& vectorBestioleProche);   
  BestiolePrevoyante(void );
  ~BestiolePrevoyante( void );          
};



#endif