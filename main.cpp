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

   Bestiole* besti[20];
   Bestiole* besti2[20];
   Bestiole* besti3[20];
   Bestiole* besti4[20];
   for (int i = 0; i<=20; i++){
      besti[i] = factory.creationBestiole(false, 4, true, true, false, false,false);
   }
   for (int i = 0; i<=20; i++){
      besti2[i] = factory.creationBestiole(false, 2, true, true, false, false,false);
   }
   for (int i = 0; i<=20; i++){
      besti3[i] = factory.creationBestiole(false, 1, true, true, false, false,false);
   }
   for (int i = 0; i<=20; i++){
      besti4[i] = factory.creationBestiole(false, 3, true, true, false, false,false);
   }
   for ( int i = 0; i <= 20; ++i ){
      ecosysteme.getMilieu().addMember(besti[i]);
      ecosysteme.getMilieu().addMember(besti2[i]);
      // ecosysteme.getMilieu().addMember(besti3[i]);
      // ecosysteme.getMilieu().addMember(besti4[i]);
   }
   ecosysteme.run();

   return 0;

}
