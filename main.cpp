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
   factory.creationBestiole(false, 4, true, true, false, false,false);
   for ( int i = 1; i <= 20; ++i )
      ecosysteme.getMilieu().addMember( BestiolePeureuse() );
   ecosysteme.run();


   return 0;

}
