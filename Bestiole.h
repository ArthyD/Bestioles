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
   double coeffDebuffCarapace;
   double coeffNageoire;


private :
   void bouge( int xLim, int yLim );


public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   Bestiole(bool pM, double t, int a, double champo, double disto, double distOr, double capaOeil, double capaOreille, double coeffCamou, double coeffCarap, double coeffDebuffCarap, double coeffNag);
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

   virtual void update(std::vector<Bestiole*>& vectorBestioleProche) {std::cout<< "Mauvais update" << std::endl;};
   void rebondit( Bestiole * b );
   virtual Bestiole* clone();
   virtual void clone(Bestiole* b);
   bool hasOeil();
   bool hasOreille();
   bool isPersoMult();
   void vieillit();
   int getX();
   int getY();
   double getOrientation();
   double getVitesse();
   int getIdentite();

   void setOrientation(double o);
   void setVitesse(double v);
};


#endif
