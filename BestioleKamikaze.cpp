#include "BestioleKamikaze.h"
#include "Bestiole.h"
#include <cmath>

double highValue = 300000;
double cibleX = 0;
double cibleY = 0;

// Fonction update 
// Entrée : listes des bestioles
// Sortie : rien
// Actions : détermine quelle est la bestiole la plus proche de la
//           bestiole courante. Actualise l'orientation de la bestiole
//           bestiole courante pour qu'elle se dirige vers la bestiole
//           la plus proche.

void BestioleKamikaze::update(vector<Bestiole*> vectorBestioleProche){
    if (vectorBestioleProche.size() > 0){
        double meilleureDistanceCarre = highValue;
        for ( std::vector<Bestiole*>::iterator it1 = vectorBestioleProche.begin();
        it1 != vectorBestioleProche.end() ; it1++ ){
            
            double deltaX = (**it1).getX() - x;
            double deltaY = (**it1).getY() - y;
            double distanceCarre = deltaX*deltaX + deltaY*deltaY;

            if (distanceCarre < meilleureDistanceCarre){
                meilleureDistanceCarre = distanceCarre;
                cibleX = (**it1).getX();
                cibleY = (**it1).getY();
            }
        }

        double deltaX = cibleX - x;
        double deltaY = cibleY - y;
        double orientation = atan(deltaY / deltaX);
    }
}