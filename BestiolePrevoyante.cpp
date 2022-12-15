#include "BestiolePrevoyante.h"
#include <cmath>

BestiolePrevoyante::BestiolePrevoyante(void){}

// Fonction : BestiolePrevoyante
// Entrée : les attributs de la bestiole
// Action : Constructeur de la bestiole
BestiolePrevoyante::BestiolePrevoyante(bool pM, double t, int a, double champo, double disto, double distOr, double capaOeil, double capaOreille, double coeffCamou, double coeffCarap, double coeffDebuffCarap, double coeffNag){
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

BestiolePrevoyante::~BestiolePrevoyante(){};
// Fonction update 
// Entrée : listes des bestioles
// Sortie : rien
// Actions : La bestiole prévoyante calcule la moyenne des orientations
//          des bestioles proches, puis les évite avec un angle de pi/2.

void BestiolePrevoyante::update(vector<std::shared_ptr<Bestiole>>& vectorBestioleProche){

    vector<double> mauvaisesOrientations;
    double moyenne;
    double nouvorientation;

    if(vectorBestioleProche.size() >= 0){
        for (auto & bestioleProche : vectorBestioleProche){
        moyenne += bestioleProche->getOrientation();
    }
        if ((moyenne - orientation)<0.001){
            if (orientation<M_PI_2){
                orientation += M_PI_2;
            } else {
                orientation -= M_PI_2;
            }
        }
    }
    
}