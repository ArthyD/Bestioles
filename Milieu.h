#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
#include "BestioleFactory.h"

#include <iostream>
#include <list>
#include <vector>


using namespace std;


class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::list<std::shared_ptr<Bestiole>>   listeBestioles;

   double                    pourcentageKamikaze = 0.15;
   double                    pourcentagePeureuse = 0.25;
   double                    pourcentageGregaire = 0.45;
   double                    pourcentagePrevoyante = 0.15;
   double                    pourcentagePersoMulti =  0.0;

   double                    probaNaissance = 0.0001;
   

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
   void addPersoAlea( void ); 
   void clone(std::shared_ptr<Bestiole> b);
   int randomPerso(void);

   void readConfig( void );

   void addMember(std::shared_ptr<Bestiole> b ) { std::cout << listeBestioles.size() << std::endl; listeBestioles.push_back(b); listeBestioles.back()->initCoords(width, height); }
   int nbVoisins( const Bestiole & b );

};


#endif
