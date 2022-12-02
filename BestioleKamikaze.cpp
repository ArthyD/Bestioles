#include "BestioleKamikaze.h"
#include "Bestiole.h"
#include <cmath>

double highValue = 300000;
double cibleX = 0;
double cibleY = 0;
double deltaX = 1;
double deltaY = 1;
double distanceCarre = 0;

BestioleKamikaze::BestioleKamikaze(void){}

BestioleKamikaze::BestioleKamikaze(bool pM, double t, int a, double champo, double disto, double distOr, double capaOeil, double capaOreille, double coeffCamou, double coeffCarap, double coeffDebuffCarap, double coeffNag){
        identite = ++next;
   cout << "Naissance Bestiole (" << identite << ") " << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE * (coeffNageoire / coeffDebuffCarapace);

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

   persoMult = pM;
   taille = t;
   anneesRestantes = a;


   champOeil = champo;
   champOreille = 2*M_PI;
   distanceOeil = disto;
   distanceOreille = distOr;
   capaciteOeil = capaOeil;
   capaciteOreille = capaOreille;
   coeffCamouflage = coeffCamou;
   coeffCarapace = coeffCarap;
   coeffDebuffCarapace = coeffDebuffCarap;
   coeffNageoire = coeffNag;
} 

BestioleKamikaze::~BestioleKamikaze(){};
// Fonction update 
// Entrée : listes des bestioles
// Sortie : rien
// Actions : détermine quelle est la bestiole la plus proche de la
//           bestiole courante. Actualise l'orientation de la bestiole
//           bestiole courante pour qu'elle se dirige vers la bestiole
//           la plus proche.
void BestioleKamikaze::update(vector<Bestiole*> & vectorBestioleProche){
    if (vectorBestioleProche.size() > 0){
        double meilleureDistanceCarre = highValue;
        for ( std::vector<Bestiole*>::iterator it1 = vectorBestioleProche.begin();
        it1 != vectorBestioleProche.end() ; it1++ ){
            
            deltaX = (**it1).getX() - x;
            deltaY = (**it1).getY() - y;
            distanceCarre = deltaX*deltaX + deltaY*deltaY;

            if (distanceCarre < meilleureDistanceCarre){
                meilleureDistanceCarre = distanceCarre;
                cibleX = (**it1).getX();
                cibleY = (**it1).getY();
            }
        }

        deltaX = cibleX - x;
        deltaY = cibleY - y;
        if (deltaX < 0) {
            orientation = M_PI + atan(deltaY / deltaX);
        }
        else if (deltaY >= 0) {
            orientation = atan(deltaY / deltaX);
        } else {
            orientation = atan(deltaY / deltaX) + 2*M_PI;
        }
    }
}