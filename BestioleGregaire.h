#ifndef _bestiolegregaire_
#define _bestiolegregaire_
#include "Bestiole.h"
#include <vector>

class BestioleGregaire : public Bestiole {        
public :  
  BestioleGregaire(bool persoMult, int age, double champOeil, double distanceOeil, double distanceOreille, double capaciteOeil, double capaciteOreille, double coeffCamouflage, double coeffCarapace, double coeffNageoire);      
  void update(vector<Bestiole*> vectorBestioleProche);        
};
#endif