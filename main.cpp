#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "BestiolePeureuse.h"
#include "BestioleFactory.h"
#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );

   BestioleFactory factory;

   Milieu mili = ecosysteme.getMilieu();
   for (int i = 0; i<=40; i++){
      mili.addPersoAlea();
   }

   ecosysteme.run();

   return 0;

}
