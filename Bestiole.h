#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"
#include <iostream>
#include <vector>


using namespace std;


class Milieu;


class Bestiole
{
   
protected :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;


   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;

   T               * couleur;

   int anneesRestantes;

   bool persoMult;
   int taille;

   double champOeil;
   double champOreille;
   double distanceOeil;
   double distanceOreille;
   double capaciteOeil;
   double capaciteOreille;
   double coeffCamouflage;
   double coeffCarapace;
   double coeffNageoire;


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

   void update(std::vector<Bestiole>& b) {};
   void rebondit( Bestiole * b );
   Bestiole clone();
   Bestiole clone(Bestiole b);
   bool hasOeil();
   bool hasOreille();
   void vieillit();
   int getX();
   int getY();
   double getOrientation();
   double getVitesse();

   void setOrientation(double o);
   void setVitesse(double v);
};


#endif
