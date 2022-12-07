#include "BestioleGregaire.h"

BestioleGregaire::BestioleGregaire(void){}

// Fonction : BestioleGregaire
// Entrée : les attributs de la bestiole
// Action : Constructeur de la bestiole
BestioleGregaire::BestioleGregaire(bool pM, double t, int a, double champo, double disto, double distOr, double capaOeil, double capaOreille, double coeffCamou, double coeffCarap, double coeffDebuffCarap, double coeffNag){
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

BestioleGregaire::~BestioleGregaire(){};

void BestioleGregaire::update(vector<std::shared_ptr<Bestiole>>& vectorBestioleProche){
    double moyenne = 0;
    if(vectorBestioleProche.size() !=0){
        for (std::vector<std::shared_ptr<Bestiole>>::iterator it = vectorBestioleProche.begin() ; it != vectorBestioleProche.end() ; it++){
                moyenne += (*it)->getOrientation();
        }
        moyenne = moyenne/vectorBestioleProche.size();
        orientation = moyenne;
    }
}