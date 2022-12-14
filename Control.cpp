#include "Control.h"

// Fonction : randomBirth
// Entrée : L'aquarium
// Sortie : rien
// Action : Fais naitre une bestiole aléatoire dans le milieu de l'aquarium
void randomBirth(Aquarium ecosysteme){
    std::cout << "Random naissance depuis control" << std::endl;
    ecosysteme.getMilieu().addPersoAlea();
}

// Fonction : killBestiole
// Entrée : Une bestiole
// Sortie : rien
// Action : détruit la bestiole
void killBestiole(std::shared_ptr<Bestiole>& bestiole){
    std::cout << "Kill depuis control" << std::endl;
    bestiole->deleteBestiole();
}

// Fonction : cloneBestiole
// Entrée : Un aquarium, une bestiole
// Sortie : rien
// Action : clone la bestiole et ajoute ce clone dans le milieu de l'aquarium
void cloneBestiole(Aquarium ecosysteme, std::shared_ptr<Bestiole>& bestiole){
    std::cout << "Clone depuis control" << std::endl;
    ecosysteme.getMilieu().addMember(bestiole->clone());
}

// Fonction : changeComportement
// Entrée : L'aquarium, une bestiole, un nouveau type à donner à la bestiole
// Sortie : rien
// Action : change le comportement de la bestiole
void changeComportement(Aquarium ecosysteme, std::shared_ptr<Bestiole>& bestiole, int newType){
    std::cout << "Changement comportement depuis control" << std::endl;
    BestioleFactory factory;
    std::shared_ptr<Bestiole> best = factory.creationBestiole(true, newType, false, false, false, false, false);
    best->cloneFromBestiole(bestiole);
    bestiole->deleteBestiole(); 
    ecosysteme.getMilieu().addMember(best);
}