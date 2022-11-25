#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"
#include <iostream>


using namespace std;


class Milieu;


class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

   const bool persoMult;
   const int taille;

   const double champOeil;
   const double champOreille;
   const double distanceOeil;
   const double distanceOreille;
   const double capaciteOeil;
   const double capaciteOreille;
   const double coeffCamouflage;
   const double coeffCarapace;
   const double coeffNageoire;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;

   T               * couleur;

   int anneesRestantes;


private :
   void bouge( int xLim, int yLim );


public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

   void update( Bestiole * b );
   void rebondit( Bestiole * b );
   Bestiole clone();
   bool hasOeil();
   bool hasOreille();
   void vieillit();

};


#endif
