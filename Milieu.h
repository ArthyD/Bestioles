#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
#include "BestiolePeureuse.h"

#include <iostream>
#include <list>
#include <vector>


using namespace std;


class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::list<BestiolePeureuse>   listeBestioles;

   float                   PourcentageKamikaze = 0.15;
   float                   PourcentagePeureuse = 0.25;
   float                   PourcentageGregaire = 0.45;
   float                   PourcentagePrevoyante = 0.15;
   float                   PourcentagePersoMulti =  0.0;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );
   void phaseAction( void );
   void phaseEnvironnement( void );
   void phaseDetection( void );
   void naissanceAlea( void );  

   void addMember( const BestiolePeureuse & b ) { listeBestioles.push_back(b); listeBestioles.back().initCoords(width, height); }
   int nbVoisins( const Bestiole & b );

};


#endif
