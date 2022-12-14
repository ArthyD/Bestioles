#include <iostream>
#include <memory>
#include "Milieu.h"
#include "Aquarium.h"


void randomBirth(Aquarium ecosysteme);
void killBestiole(std::shared_ptr<Bestiole>& bestiole);
void cloneBestiole(Aquarium ecosysteme, std::shared_ptr<Bestiole>& bestiole);
void changeComportement(Aquarium ecosysteme, std::shared_ptr<Bestiole>& bestiole, int newType);