#include "BestioleKamikaze.h"
#include <cmath>

double highValue = 300000;

void BestioleKamikaze::update(vector<Bestiole*> vectorBestioleProche){
    if (vectorBestioleProche.size() > 0){
        double meilleureDistanceCarre = highValue;
        for (auto & bestioleProche : vectorBestioleProche){
            double deltaX = bestioleProche.getX() - this.getX();
            double deltaY = bestioleProche.getY() - this.getY();
            double distanceCarre = deltaX*deltaX + deltaY*deltaY;
            if (distanceCarre < meilleureDistanceCarre){
                meilleureDistanceCarre = distanceCarre;
                double cible = bestioleProche;
            }
        }
        if (deltaX < 0){
            double orientation = atan(deltaX / deltaY);
        }
    }
}