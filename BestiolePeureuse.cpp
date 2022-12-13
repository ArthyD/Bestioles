#include "BestiolePeureuse.h"
#include <cmath>

BestiolePeureuse::BestiolePeureuse(void)
{
   agoraphobe = 2;
   fuite = false;
   compteur = 1000;
}
BestiolePeureuse::~BestiolePeureuse(void)
{

}

// Fonction : BestiolePeureuse
// Entrée : les attributs de la bestiole
// Action : Constructeur de la bestiole
BestiolePeureuse::BestiolePeureuse(bool pM, double t, int a, double champo, double disto, double distOr, double capaOeil, double capaOreille, double coeffCamou, double coeffCarap, double coeffDebuffCarap, double coeffNag){
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
   
   agoraphobe = 2;
   fuite = false;
   compteur = 1000;
} 

void BestiolePeureuse::setAgoraphobie(int agor){
    agoraphobe = agor;
}



void BestiolePeureuse::update(std::vector<std::shared_ptr<Bestiole>>& vectorBestioleProche){
    if (fuite){
        if (compteur == 0) {
            fuite = false;
            vitesse = vitesse / 2;
        } else {
            compteur -=1;
        }
    } else if(vectorBestioleProche.size() >= agoraphobe){
        double pi = M_PI;
        fuite = true;
        if (orientation < pi){
            orientation += pi;
        } else {
            orientation -= pi;
        }
        vitesse = vitesse * 2;
        compteur = 1000;
    }
}

bool BestiolePeureuse::getFuite(){
    return fuite;
}