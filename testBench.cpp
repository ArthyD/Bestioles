#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "BestiolePeureuse.h"
#include "BestioleFactory.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;


// Fonction : test
// Entrée : une condition, et un string qui explique ce qu'on attend de la condition
// Action : Teste la condition et l'affiche
void test(bool condition, const std::string& prompt)
{
    std::cout << prompt << ": ";
    if (condition)
       std::cout << "true" << std::endl;
    else
       std::cout << "false" << std::endl;
}
// Fonction : testBestiole
// Action : Teste la classe Aquarium
void testAquarium(){
    cout<< "*** Test Aquarium.cpp***"<<endl;
    cout<<"***Test constructeur et destructeur***"<<endl;
    Aquarium* aquarium1 = new Aquarium(200,200,5);
    delete(aquarium1);

    cout<<"***Test run***"<<endl;
    Aquarium* aquarium2 = new Aquarium(200,200,5);
    aquarium2->run();
    delete(aquarium2);
}

//Fonction : testBestiole
//Action : Tester les méthodes de la classe Bestiole
void testBestiole(){
    cout<< "*** Test Bestiole.cpp***"<<endl;
    cout<< "*** Test du premier constructeur***"<<endl;
    //On teste quelques paramètres.
    Bestiole bestioleC1 = Bestiole();
    test(bestioleC1.getX()==0,"Cstor should return x=0");
    test(bestioleC1.getY()==0,"Cstor should return y=0");
    test(bestioleC1.getTaille()==0,"Cstor should return taille=1");
    cout << "*** Test du deuxième constructeur (constructeur de copies)***"<<endl;
    //On teste quelques paramètres.
    Bestiole bestioleC1copy = Bestiole(bestioleC1);
    test(bestioleC1copy.getX()==0,"Cstor should return x=0");
    test(bestioleC1copy.getY()==0,"Cstor should return y=0");
    test(bestioleC1copy.getTaille()==0,"Cstor should return taille=1");
    bestioleC1copy.~Bestiole();
    bestioleC1.~Bestiole();
    cout<< "*** Test du troisième constructeur***"<<endl;
    //Ce troisième constructeur est override par les différentes personnalitées, ainsi on le
    //testera dans celles-ci.

    cout << "**** Test du jeTeVois avec des yeux****" << endl;
    //Nous testons seulement le cas sans carapace et avec des yeux pour tester la formule
    // mathématique.
    BestioleFactory* factory2 = new BestioleFactory();
    shared_ptr<Bestiole> bestiole1 = factory2->creationBestiole(false,4,false,true,false,false,false);
    shared_ptr<Bestiole> bestiole2 = factory2->creationBestiole(false,4,false,true,false,false,false);
    shared_ptr<Bestiole> bestiole3 = factory2->creationBestiole(false,4,false,true,false,false,false);
    shared_ptr<Bestiole> bestiole4 = factory2->creationBestiole(false,4,false,true,false,false,false);
    shared_ptr<Bestiole> bestiole5 = factory2->creationBestiole(false,4,false,true,false,false,false);
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
    delete(factory2);

    cout << "**** Test du jeTeVois avec des oreilles****" << endl;
    BestioleFactory* factory3 = new BestioleFactory();
    shared_ptr<Bestiole> bestiole11 = factory3->creationBestiole(false,4,true,false,false,false,false);
    shared_ptr<Bestiole> bestiole22 = factory3->creationBestiole(false,4,false,false,false,false,false);
    shared_ptr<Bestiole> bestiole33 = factory3->creationBestiole(false,4,false,true,false,false,false);
    shared_ptr<Bestiole> bestiole44 = factory3->creationBestiole(false,4,false,true,false,false,false);
    shared_ptr<Bestiole> bestiole55 = factory3->creationBestiole(false,4,false,true,false,false,false);
    cout << "Les bestioles sont créées"<< endl;
    bestiole11->setOrientation(0.785);
    bestiole11->setCapaciteOreille(1);
        cout << "Les bestioles sont oreillées"<< endl;
    bestiole11->setDistanceOreille(3);
        cout << "Les bestioles sont distanciées"<< endl;
    bestiole11->setPosition(6,7);
        cout << "Les bestioles sont positionnées"<< endl;
    bestiole22->setPosition(10,8);
    bestiole33->setPosition(4,5);
    bestiole44->setPosition(8,9);
    bestiole55->setPosition(7,9);

    cout << "Les bestioles sont réglées"<< endl;
    cout << "Voit-on la bestiole 2 ? "<< bestiole11->jeTeVois(*bestiole22) << endl;
    cout << "Voit-on la bestiole 3 ? "<< bestiole11->jeTeVois(*bestiole33) << endl;
    cout << "Voit-on la bestiole 4 ? "<< bestiole11->jeTeVois(*bestiole44) << endl;
    cout << "Voit-on la bestiole 5 ? "<< bestiole11->jeTeVois(*bestiole55) << endl;
    //si on voit la 2, 3 et 5, ça marche
    delete(factory3);

    cout << "**** Test du rebondit ****" << endl;
    Bestiole bestioleRebondissante = Bestiole();
    bestioleRebondissante.setOrientation(0);
    bestioleRebondissante.rebondit();
    test(bestioleRebondissante.getOrientation()<3.17,"La bestiole devrait avoir rebondit");
    bestioleRebondissante.~Bestiole();

    cout << "**** Test de la collision ****" << endl;
    BestioleFactory* factory4 = new BestioleFactory();
    shared_ptr<Bestiole> bestiole41 = factory4->creationBestiole(false,4,true,false,false,false,false);
    shared_ptr<Bestiole> bestiole42 = factory4->creationBestiole(false,4,false,false,false,false,false);
    (*bestiole41).setPosition(0,0);
    (*bestiole41).setPosition(0,0);
    test(bestiole41->checkCollision(bestiole42),"Les bestioles devraient se rentrer dedans");
    (*bestiole41).setPosition(0,0);
    (*bestiole41).setPosition(100,100);
    test(!(bestiole41->checkCollision(bestiole42)),"Les bestioles ne devraient pas se rentrer dedans");
    delete(factory4);

    cout << "**** Test de bouge ****" << endl;
    BestioleFactory* factory5 = new BestioleFactory();
    shared_ptr<Bestiole> bestiole51 = factory5->creationBestiole(false,4,true,false,false,false,false);
    (*bestiole51).setPosition(0,5);
    (*bestiole51).setOrientation(1.57);
    (*bestiole51).setVitesse(2);
    Milieu flotte1 = Milieu( 10, 10 );
    (*bestiole51).action(flotte1);
    test(((*bestiole51).getX()<0.0016),"La coordonnée X doit avoir été bien calculée");
    test(((*bestiole51).getY()<3.2),"La coordonnée Y doit avoir été bien calculée");
    delete(factory4);
}

//Fonction : testBestioleFactory
//Action :  tester les méthodes de BestioleFactory
void testBestioleFactory(){
    cout << "*** Test BestioleFactory.cpp***" << endl;
    cout << "*** Test readConfig()***" << endl;
    BestioleFactory* factory1 = new BestioleFactory();
    delete(factory1);


    cout << "**** Test creationBestiole() ****" << endl;
    BestioleFactory* factory = new BestioleFactory();
    factory->creationBestiole(false,2,true,false,false,false,false);
    delete(factory);

    cout << "**** Test lecture du fichier ****" << endl;
    //A faire
}

//Fonction : testBestioleGregaire
//Action : tester les méthodes de BestioleGrégaire
void testBestioleGregaire(){
    cout<< "*** Test BestioleGregaire.cpp***"<<endl;
    cout<< "*** Test du constructeur***"<<endl;
    //A faire

    cout<< "*** Test update grégaire***"<<endl;
    BestioleFactory* factory = new BestioleFactory();
    shared_ptr<Bestiole> bestiole = factory->creationBestiole(false,4,true,false,false,false,false);
    shared_ptr<Bestiole> bestiole2 = factory->creationBestiole(false,4,true,false,false,false,false);
    BestioleGregaire* bestioleGregaire = new BestioleGregaire(false,2,1,0,0,0,0,0,0,0,0,0);
    vector<std::shared_ptr<Bestiole>> bestioleProche = {bestiole,bestiole2};
    (*bestiole).setOrientation(3.14);
    (*bestiole2).setOrientation(0);
    bestioleGregaire->update(bestioleProche);
    test(bestioleGregaire->getOrientation()<=3.14,"L'update doit changer l'orientation");
    bestioleGregaire->~BestioleGregaire();
    }


//Fonction : testBestioleKamikaze
//Action : tester les méthodes de BestioleKamikaze
void testBestioleKamikaze(){
    cout<< "*** Test BestioleKamikaze.cpp***"<<endl;
    cout<< "*** Test du constructeur***"<<endl;
    //A faire

    cout<< "*** Test update kamikaze***"<<endl;
    BestioleFactory* factory = new BestioleFactory();
    shared_ptr<Bestiole> bestiole = factory->creationBestiole(false,4,true,false,false,false,false);
    shared_ptr<Bestiole> bestiole2 = factory->creationBestiole(false,4,true,false,false,false,false);
    BestioleKamikaze* bestioleKamikaze = new BestioleKamikaze(false,2,1,0,0,0,0,0,0,0,0,0);
    vector<std::shared_ptr<Bestiole>> bestioleProche = {bestiole,bestiole2};
    (*bestiole).setPosition(2,4);
    (*bestiole2).setPosition(8,8);
    bestioleKamikaze->setPosition(1,3);
    bestioleKamikaze->update(bestioleProche);
    test(bestioleKamikaze->getOrientation()<=0.79,"L'update doit changer l'orientation");
    bestioleKamikaze->~BestioleKamikaze();
}

//Fonction : testBestiolePeureuse
//Action : tester les méthodes de BestiolePeureuse
void testBestiolePeureuse(){
    cout<< "*** Test BestiolePeureuse.cpp***"<<endl;
    cout<< "*** Test du premier constructeur***"<<endl;
    //A faire
    cout<< "*** Test update peureuse***"<<endl;
    BestioleFactory* factory = new BestioleFactory();
    shared_ptr<Bestiole> bestiole = factory->creationBestiole(false,4,true,false,false,false,false);
    shared_ptr<Bestiole> bestiole2 = factory->creationBestiole(false,4,true,false,false,false,false);
    BestiolePeureuse* bestiolePeureuse = new BestiolePeureuse(false,2,1,0,0,0,0,0,0,0,0,0);
    vector<std::shared_ptr<Bestiole>> bestioleProche = {bestiole,bestiole2};
    bestiolePeureuse->setOrientation(0);
    bestiolePeureuse->update(bestioleProche);
    test(bestiolePeureuse->getOrientation()<=3.15,"L'update doit changer l'orientation");
    test(bestiolePeureuse->getFuite(),"L'update doit faire fuire la bestiole");
    bestiolePeureuse->~BestiolePeureuse();

}

//Fonction : testBestiolePrevoyante
//Action : tester les méthodes de BestiolePeureuse
void testBestiolePrevoyante(){
    cout<< "*** Test BestiolePrevoyante.cpp***"<<endl;
    cout<< "*** Test du premier constructeur***"<<endl;
    //A faire
    cout<< "*** Test update prevoyante***"<<endl;
    BestioleFactory* factory = new BestioleFactory();
    shared_ptr<Bestiole> bestiole = factory->creationBestiole(false,4,true,false,false,false,false);
    BestiolePrevoyante* bestiolePrevoyante = new BestiolePrevoyante(false,2,1,0,0,0,0,0,0,0,0,0);
    vector<std::shared_ptr<Bestiole>> bestioleProche = {bestiole};
    (*bestiole).setOrientation(0.75);
    bestiolePrevoyante->setOrientation(0);
    bestiolePrevoyante->update(bestioleProche);
    test(bestiolePrevoyante->getOrientation()<=1.58,"L'update doit changer l'orientation");
    bestiolePrevoyante->~BestiolePrevoyante();

}

//Fonction : testBestiolePM
//Action : tester les clonages des bestioles à personnalité multiple
void testBestiolePM(){}

//Fonction : testMilieu
//Action : tester les méthodes de Milieu
void testMilieu(){}



int main()
{
    cout << "**** Test bench ****" << endl;
   
    //testAquarium();
    //testBestiole();
    //testBestioleGregaire();
    //testBestioleKamikaze();
    //testBestiolePeureuse();
    testBestiolePrevoyante();
    
    

}