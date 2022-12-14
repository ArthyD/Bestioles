#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"
#include <iostream>
#include <vector>
#include <memory>


using namespace std;


class Milieu;


class Bestiole
{
   
protected :

   static const double     MAX_VITESSE;
   static int              next;


   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;

   T               * couleur;

   int anneesRestantes;

   bool persoMult;
   bool hasToBeDeleted = false;
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

   virtual void update(std::vector<std::shared_ptr<Bestiole>>& vectorBestioleProche) {std::cout<< "Mauvais update" << std::endl;};
   void vieillit();

   void rebondit();
   bool checkCollision(std::shared_ptr<Bestiole> b);
   bool collision();
   
   std::shared_ptr<Bestiole> clone();
   void cloneFromBestiole(std::shared_ptr<Bestiole>& bestiolePrototype);

   // Les getters
   bool hasOeil();
   bool hasOreille();
   bool isPersoMult();
   int getX();
   int getY();
   double getOrientation();
   double getVitesse();
   int getIdentite();
   int getAnneesRestantes();
   int getTaille();
   
   bool isDeletedSoon();

   // Les setters
   void setOrientation(double o);
   void setVitesse(double v);
   void setPosition(int a, int b);
   void setCapaciteOeil(double o);
   void setChampOeil(double o);
   void setDistanceOeil(double o);
   void setDistanceOreille(double o);
   void setCapaciteOreille(double o);


   //destructeur
   void deleteBestiole();
};


#endif
