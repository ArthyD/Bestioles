#include "Aquarium.h"
#include "Milieu.h"
#include <iostream>
#include <fstream>
#include "Control.h"

using namespace std;


int main()
{
   int nombreBestioles = 0;
   ifstream fichier("./config.txt", ios::in);
   if (fichier)
   {
            std::string ligne;
            std::string champ;
            double valeur;
            for (int i =0;  i < 30; i++)
        {
            getline(fichier, ligne);
            std::size_t pos = ligne.find("=");
            champ = ligne.substr(0,pos);
            valeur = stoi(ligne.substr(pos+1));
            if (champ == "Nombre de Bestioles") {
             nombreBestioles = valeur;
            }
        }
   }
   Aquarium       ecosysteme( 640, 480, 30 );
   for (int i = 0; i<=nombreBestioles - 1; i++){
      ecosysteme.getMilieu().addPersoAlea();
   }

   ecosysteme.run();

   return 0;
}
