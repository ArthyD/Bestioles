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

   for (int i = 0; i<=20; i++){
      besti[i] = factory.creationBestiole(false, 3, true, true, false, false,false);
   }
   for ( int i = 0; i <= 20; ++i ){
      ecosysteme.getMilieu().addMember(besti[i]);
   }
   ecosysteme.run();

   return 0;

}
