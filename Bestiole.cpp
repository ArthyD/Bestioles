#include "Bestiole.h"

#include "Milieu.h"

#include <cstdlib>
#include <cmath>
#include <memory>


const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 50.;

int               Bestiole::next = 0;

 /*********** Constructeurs et destructeurs **********/

// Fonction : Bestiole
// Entrée : rien
// Action : Constructeur de la bestiole
Bestiole::Bestiole( void ){
   identite = ++next;

   //cout << "const Bestiole (" << identite << ") par defaut" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

   persoMult = false ;
   taille = 1 ;

   champOeil =0;
   champOreille =0;
   distanceOeil = 0;
   distanceOreille = 0;
   capaciteOeil = 0;
   capaciteOreille = 0;
   coeffCamouflage = 0;
   coeffCarapace = 1;
   coeffDebuffCarapace = 1;
   coeffNageoire = 1;
}

// Fonction : Bestiole
// Entrée : une bestiole
// Action : Constructeur de la bestiole
Bestiole::Bestiole( const Bestiole & b ){
   identite = ++next;
   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   couleur = new T[ 3 ];
   memcpy( couleur, b.couleur, 3*sizeof(T) );
}

// Fonction : Bestiole
// Entrée : les attributs de la bestiole
// Action : Constructeur de la bestiole
Bestiole::Bestiole(bool pM, double t, int a, double champo, double disto, double distOr, double capaOeil, double capaOreille, double coeffCamou, double coeffCarap, double coeffDebuffCarap, double coeffNag){} 

// Fonction : ~Bestiole
// Entrée : les attributs de la bestiole
// Action : le destructeur
Bestiole::~Bestiole( void )
{

   delete[] couleur;

   cout << "dest Bestiole " << this << endl;

}

 /*********** Visions et mise à jour des attributs **********/

// Fonction : jeTeVois
// Entrée : Une bestiole
// Sortie : Un booléen
// Action : Détermine si une bestiole est vue par la bestiole
// (prend en compte capteurs et accessoires).
bool Bestiole::jeTeVois( const Bestiole & b ) const{
   double dist;
   double dotproduct;
   double angleEntreBestioles;
   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   vector<double> vecteurBestiole;
   vector<double> vecteurEntreBestioles;
   if (capaciteOeil<=b.coeffCamouflage){
      if (capaciteOreille<=b.coeffCamouflage){
         return (false);
      } else {
         if (distanceOreille<dist){
            return(false);
         }else{
            return (true);
         }
      }
   }
   if (capaciteOreille<=b.coeffCamouflage){
      if (capaciteOeil<=b.coeffCamouflage){
         return (false);
      } else if (distanceOeil<dist){
         return (false);
      } else {
         vecteurBestiole.push_back(cos(orientation));
         vecteurBestiole.push_back(sin(orientation));
         vecteurEntreBestioles.push_back((b.x-x)/dist);
         vecteurEntreBestioles.push_back((b.y-y)/dist);
         for(int i=0;i<vecteurBestiole.size();i++){
            dotproduct += vecteurBestiole[i] * vecteurEntreBestioles[i];
         }
         if (dotproduct<0){
            dotproduct+=1;
         }
         angleEntreBestioles = acos(dotproduct);
         if (angleEntreBestioles<=champOeil/2){
            return(true);
         } else {
            return false;
         }
      }
   }
}

void Bestiole::rebondit(){
   double pi = M_PI;
   if (orientation < pi){
            orientation += pi;
        } else {
            orientation -= pi;
        }
}

// Fonction : checkCollision
// Entrée : Deux bestioles
// Sortie : Booléen
// Action : Détermine si deux bestioles se touchent
// (prend en compte la distance entre les deux bestioles, et leur taille).
bool Bestiole::checkCollision(std::shared_ptr<Bestiole> bestiole2){
   int x1 = this->x;
   int x2 = (*bestiole2).getX();
   int y1 = this->y;
   int y2 = (*bestiole2).getY();
   int taille1 = this->taille;
   int taille2 = (*bestiole2).getTaille();
   int distanceCarre = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
   return (distanceCarre < (taille1)/2 + (taille2)/2);
}

// Fonction : collision
// Entrée : Une bestiole
// Sortie : Rien
// Action : Détermine si une bestiole meurt suite à une collision
// (prend en compte la carapace de la bestiole).
// Si la bestiole ne meurt pas, elle rebondie.
bool Bestiole::collision(){
   double carap = this->coeffCarapace;
   double probaMort = (((double) std::rand())/ (double) RAND_MAX)/carap;
   cout << "proba de mourir " << probaMort << endl;
   return (probaMort > 0.5);
}

 /*********** Clonage **********/

// Fonction : clone
// Entrée : rien
// Sortie : Un pointeur vers une bestiole
// Action : clone la bestiole
std::shared_ptr<Bestiole> Bestiole::clone()
{
   std::shared_ptr<Bestiole> clone = make_shared<Bestiole>();
   clone->next=next;
   clone->identite=identite;
   clone->x=x;
   clone->y=y;
   clone->cumulX=cumulX;
   clone->cumulY=cumulY;
   clone->vitesse=vitesse;
   clone->orientation=orientation;
   clone->anneesRestantes=anneesRestantes;
   clone->couleur=couleur;
   clone->persoMult=persoMult;
   clone->taille=taille;
   clone->champOeil=champOeil;
   clone->champOreille=champOreille;
   clone->distanceOeil=distanceOeil;
   clone->distanceOreille=distanceOreille;
   clone->capaciteOeil=capaciteOeil;
   clone->capaciteOreille=capaciteOreille;
   clone->coeffCamouflage=coeffCamouflage;
   clone->coeffCarapace=coeffCarapace;
   clone->coeffDebuffCarapace=coeffDebuffCarapace;
   clone->coeffNageoire=coeffNageoire;
   return clone;
} 

// Fonction : cloneFromBestiole
// Entrée : Une bestiole
// Sortie : rien
// Action : on récupère tout les attributs de la bestiole en entrée
void Bestiole::cloneFromBestiole(std::shared_ptr<Bestiole>& bestiolePrototype)
{
   next=bestiolePrototype->next;
   identite=bestiolePrototype->identite;
   x=bestiolePrototype->x;
   y=bestiolePrototype->y;
   cumulX=bestiolePrototype->cumulX;
   cumulY=bestiolePrototype->cumulY;
   orientation=bestiolePrototype->orientation;
   vitesse=bestiolePrototype->vitesse;
   couleur=bestiolePrototype->couleur;
   anneesRestantes=bestiolePrototype->anneesRestantes;
   persoMult=bestiolePrototype->persoMult;
   taille=bestiolePrototype->taille;
   champOeil=bestiolePrototype->champOeil;
   champOreille=bestiolePrototype->champOreille;
   distanceOeil=bestiolePrototype->distanceOeil;
   distanceOreille=bestiolePrototype->distanceOreille;
   capaciteOeil=bestiolePrototype->capaciteOeil;
   capaciteOreille=bestiolePrototype->capaciteOreille;
   coeffCamouflage=bestiolePrototype->coeffCamouflage;
   coeffCarapace=bestiolePrototype->coeffCarapace;
   coeffDebuffCarapace=bestiolePrototype->coeffDebuffCarapace;
   coeffNageoire=bestiolePrototype->coeffNageoire;
} 

 /*********** Getters and setters **********/
bool Bestiole::hasOreille(){
   return capaciteOreille!=0;
}

bool Bestiole::hasOeil(){
   return capaciteOeil!=0;
}

bool Bestiole::isPersoMult(){
   return persoMult;
}

void Bestiole::vieillit(){
   anneesRestantes = anneesRestantes - 1;
}

int Bestiole::getX(){
   return x;
}

int Bestiole::getY(){
   return y;
}

double Bestiole::getOrientation(){
   return orientation;
}

double Bestiole::getVitesse(){
   return vitesse;
}
int Bestiole::getIdentite(){
   return identite;
}

int Bestiole::getAnneesRestantes(){
   return anneesRestantes;
}

int Bestiole::getTaille(){
   return taille;
}
void Bestiole::setVitesse(double v){
   vitesse = v;
}

void Bestiole::setOrientation(double o){
   orientation = o;
}


void Bestiole::setPosition(int a, int b){
   x = a;
   y = b;
}
void Bestiole::setCapaciteOeil(double o){
   capaciteOeil = o;
}

void Bestiole::setCapaciteOreille(double o){
   capaciteOreille = o;
}
void Bestiole::setChampOeil(double o){
   champOeil = o;
}
void Bestiole::setDistanceOeil(double o){
   distanceOeil = o;
}
void Bestiole::setDistanceOreille(double o){
   distanceOreille = o;
}

void Bestiole::deleteBestiole(){
   hasToBeDeleted = true;
}

bool Bestiole::isDeletedSoon(){
   return hasToBeDeleted;
}


void Bestiole::draw( UImg & support )
{
   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;


   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );
}

 /*********** Déplacements **********/
void Bestiole::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}

void Bestiole::bouge( int xLim, int yLim ){

   double         nx, ny;
   double         dx = cos( orientation )*vitesse;
   double         dy = -sin( orientation )*vitesse;
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

}

void Bestiole::action(Milieu & monMilieu){
   bouge( monMilieu.getWidth(), monMilieu.getHeight() );
}

bool operator==( const Bestiole & b1, const Bestiole & b2 ){
   return ( b1.identite == b2.identite );
}