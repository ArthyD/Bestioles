#include <iostream>
#include "BestioleFactory.h"

using namespace std;


int main()
{
    cout << "**** Test bench ****" << endl;

    cout << "**** Test des apparitions des bestioles ****" << endl;
    BestioleFactory* factory = new BestioleFactory();
    factory->creationBestiole(false,2,true,false,false,false,false);
    delete(factory);
    cout << "**** Test des capteurs ****" << endl;

    cout << "**** Test des updates selon les comportements ****" << endl;

    cout << "**** Test du clonage ****" << endl;

    cout << "**** Test des rebonds ****" << endl;

}