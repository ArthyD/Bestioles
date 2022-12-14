
#include "BestioleFactory.h"

#include <stdlib.h>
#include <fstream>
#include <string>
#include <cmath>


// Nous instantions les paramètres définissant les bestioles
double distanceOreille = 0;
double capaciteOreille = 0;
double champOeil = 0;
double distanceOeil = 0;
double capaciteOeil = 0;
double coeffCamouflage = 0;
double coeffCarapace = 1; 
double coeffDebuffCarapace = 1;
double coeffNageoire = 1;

// Fonction : BestioleFactory
// Entrée : Rien
// Action : Construction de la Factory à partir du fichier config.txt pour
// définir les paramètres des bestioles
BestioleFactory::BestioleFactory()
{
    readConfig();

}

BestioleFactory::~BestioleFactory()
{}

// Fonction : randomDouble
// Entrée : Un double minimum et un double maximum qui définissent les bornes des paramètres.
// Action : Génère un double entre ces bornes pour définir le paramètre lors de la création de Bestiole.
double BestioleFactory::randomDouble(double min, double max) {
    return min +  static_cast<double>( rand() )/RAND_MAX*max;
}

// Fonction : readConfig
// Entrée : void
// Action : Traite le fichier texte pour définir les bornes des valeurs des paramètres.
void BestioleFactory::readConfig(void)
{

   ifstream fichier("./config.txt", ios::in);
   if (fichier)
   {
            std::string ligne;
            std::string champ;
            double valeur;
            for (int i =0;  i < 32; i++)
        {
            getline(fichier, ligne);
            std::size_t pos = ligne.find("=");
            champ = ligne.substr(0,pos);
            valeur = stod(ligne.substr(pos+1));
            if (champ == "Champ Oeil Maximal") {
             champOeilMax = valeur;
            }
            if (champ == "Champ Oeil Mininal") {
                champOeilMin = valeur;
            }
            if (champ == "Distance de vue Maximale") {
             distanceOeilMax = valeur;
            }            
            if (champ == "Distance de vue Minimale") {
             distanceOeilMin = valeur;
            }
            if (champ == "Capacite Oeil Maximale") {
             capaciteOeilMax = valeur;
            }
            if (champ == "Capacite Oeil Mininale") {
             capaciteOeilMin = valeur;
            }
            if (champ == "Distance Oreille Mininale") {
              distanceOreilleMin = valeur;
            }
            if (champ == "Distance Oreille Maximale") {
             distanceOreilleMax = valeur;
            }            
            if (champ == "Capacite Oreille Maximale") {
             capaciteOreilleMax = valeur;
            }
            if (champ == "Capacite Oreille Minimale") {
             capaciteOreilleMin = valeur;
            }
            if (champ == "Coefficient Nageoire") {
                coeffNageoire = valeur;
            }
            if (champ == "Coefficient Carapace Maximal") {
                coeffCarapaceMax = valeur;
            }
            if (champ == "Coefficient Debuff Carapace Maximal") {
             coeffDebuffCarapaceMax = valeur;
            }            
            if (champ == "Coefficient Camouflage Maximal") {
             coeffCamouflageMax = valeur;
            }
            if (champ == "Coefficient Camouflage Mininmal") {
             coeffCamouflageMin = valeur;
            }
            if (champ == "Agoraphobie Minimale") {
                agoraMin = valeur;
            }
            if (champ == "Agoraphobie Maximale") {
                agoraMax = valeur;
            }            
            if (champ == "Taille Maximale") {
                taillemax = valeur;
            }
            if (champ == "Age Maximal") {
                agemax = valeur;
            }                       
        }
   }
   else {
      cerr << "Impossible d'ouvrir le fichier de configuration !" << endl;
   }
   fichier.close();
}

std::shared_ptr<Bestiole> BestioleFactory::creationBestiole(bool persoMult, int type, bool aOreille, bool aYeux, bool aCamouflage, bool aCarapace, bool aNageoires){
    
    if (aOreille){
        distanceOreille = randomDouble(distanceOreilleMin,distanceOreilleMax); 
        capaciteOreille = randomDouble(capaciteOreilleMin,capaciteOreilleMax);
    } else {
        distanceOreille = 0.0;
        capaciteOreille = 0.0;
    }
    
    if (aYeux) {
        champOeil = randomDouble(champOeilMin,champOeilMax); 
        distanceOeil = randomDouble(distanceOeilMin,distanceOeilMax); 
        capaciteOeil = randomDouble(capaciteOeilMin,capaciteOeilMax); 
    } else {
        champOeil = 0.0;
        distanceOeil = 0.0;
        capaciteOeil = 0.0;
    }
       
    
    if (aCamouflage){
        coeffCamouflage = randomDouble(coeffCamouflageMin,coeffCamouflageMax); 
    } else {
        coeffCamouflage = 0.0;
    }
    
    if (aCarapace){
        coeffCarapace = randomDouble(1.0,coeffCarapaceMax); 
        coeffDebuffCarapace = randomDouble(1.0, coeffDebuffCarapaceMax);
    } else {
        coeffCarapace = 1.0;
        coeffDebuffCarapace = 1.0;
    }
    
    if (aNageoires){
        coeffNageoire = randomDouble(1.0,coeffNageoire);
    } else {
        coeffNageoire = 1.0;
    }
    
    int age = rand() % (agemax + 1);
    double taille = randomDouble(5.0,taillemax);
    //création de la bestiole choisie via le type
    if (type==1){
        return std::make_shared<BestioleKamikaze>(persoMult, taille, age, champOeil, distanceOeil, distanceOreille, capaciteOeil, capaciteOreille, coeffCamouflage, coeffCarapace, coeffDebuffCarapace, coeffNageoire);
    } 
    if (type ==2){
        return std::make_shared<BestioleGregaire>(persoMult, taille, age, champOeil, distanceOeil, distanceOreille, capaciteOeil, capaciteOreille, coeffCamouflage, coeffCarapace, coeffDebuffCarapace, coeffNageoire);
    } 
    else if (type ==3){
        return std::make_shared<BestiolePrevoyante>(persoMult, taille, age, champOeil, distanceOeil, distanceOreille, capaciteOeil, capaciteOreille, coeffCamouflage, coeffCarapace, coeffDebuffCarapace, coeffNageoire);
    } 
    if (type ==4) {
        int agoraphobie = agoraMin + rand() % (agoraMax - agoraMin +1);
        auto b = std::make_shared<BestiolePeureuse>(persoMult, taille, age, champOeil, distanceOeil, distanceOreille, capaciteOeil, capaciteOreille, coeffCamouflage, coeffCarapace, coeffDebuffCarapace, coeffNageoire) ;
        b->setAgoraphobie(agoraphobie);
        return b;
    } else {
        return NULL;
    }
}