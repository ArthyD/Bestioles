#include <iostream>
#include "BestioleFactory.h"
#include <cmath>

using namespace std;


int main()
{
    cout << "**** Test bench ****" << endl;

    cout << "**** Test des apparitions des bestioles ****" << endl;
    BestioleFactory* factory = new BestioleFactory();
    factory->creationBestiole(false,2,true,false,false,false,false);
    cout << "**** Test des capteurs ****" << endl;

    cout << "**** Test des updates selon les comportements ****" << endl;

    cout << "**** Test du clonage ****" << endl;

    cout << "**** Test des rebonds ****" << endl;

    cout << "**** Test du jeTeVois ****" << endl;

    Bestiole* bestiole1 = factory->creationBestiole(false,4,false,true,false,false,false);
    Bestiole* bestiole2 = factory->creationBestiole(false,4,false,true,false,false,false);
    Bestiole* bestiole3 = factory->creationBestiole(false,4,false,true,false,false,false);
    Bestiole* bestiole4 = factory->creationBestiole(false,4,false,true,false,false,false);
    Bestiole* bestiole5 = factory->creationBestiole(false,4,false,true,false,false,false);
    cout << "Les bestioles sont créées"<< endl;
    bestiole1->setOrientation(0.785);
    bestiole1->setCapaciteOeil(1);
        cout << "Les bestioles sont orientées"<< endl;
    bestiole1->setChampOeil(M_PI_4);
        cout << "Les bestioles sont oeillées"<< endl;
    bestiole1->setDistanceOeil(5);
        cout << "Les bestioles sont distanciées"<< endl;
    bestiole1->setPosition(6,7);
        cout << "Les bestioles sont positionnées"<< endl;
    bestiole2->setPosition(10,8);
    bestiole3->setPosition(4,5);
    bestiole4->setPosition(8,9);
    bestiole5->setPosition(7,9);

    cout << "Les bestioles sont réglées"<< endl;
    cout << "Voit-on la bestiole 2 ? "<< bestiole1->jeTeVois(*bestiole2) << endl;
    cout << "Voit-on la bestiole 3 ? "<< bestiole1->jeTeVois(*bestiole3) << endl;
    cout << "Voit-on la bestiole 4 ? "<< bestiole1->jeTeVois(*bestiole4) << endl;
    cout << "Voit-on la bestiole 5 ? "<< bestiole1->jeTeVois(*bestiole5) << endl;
    //si on voit la 4 et l5, ça marche
    
    delete(factory);
}