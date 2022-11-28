#include "bestioleprevoyante.h"

void bestiolePrevoyante::update(vector<bestiole*> vectorBestioleProche){

    vector<double> mauvaisesOrientations;

    for (auto & bestioleProche : vectorBestioleProche){
        mauvaisesOrientations.add(bestioleProche.getOrientation())
    }

    double meilleurEcart = 0;
    double meilleureOrientation = this.getOrientation();
    for (int i=0; i<mauvaisesOrientations.size(); i++){
        for (int j=i; j<mauvaisesOrientations.size(); i++){
            double ecart = abs(mauvaisesOrientations.get(i) - mauvaisesOrientations.get(j));
            if (ecart > meilleurEcart){
                meilleurEcart = ecart;
                double meilleureOrientation = (mauvaisesOrientations.get(i) + mauvaisesOrientations.get(j)) / 2;
            }
        }
    }
    this.setOrientation(meilleureOrientation);
}