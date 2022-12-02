#include "Bestiole.h"

#include "Milieu.h"

#include <cstdlib>
#include <cmath>


const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 50.;

int               Bestiole::next = 0;


Bestiole::Bestiole( void )
{

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


Bestiole::Bestiole( const Bestiole & b )
{

   identite = ++next;

   //cout << "const Bestiole (" << identite << ") par copie" << endl;

   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   couleur = new T[ 3 ];
   memcpy( couleur, b.couleur, 3*sizeof(T) );

}


Bestiole::~Bestiole( void )
{

   delete[] couleur;

   cout << "dest Bestiole" << endl;

}

Bestiole::Bestiole(bool pM, double t, int a, double champo, double disto, double distOr, double capaOeil, double capaOreille, double coeffCamou, double coeffCarap, double coeffDebuffCarap, double coeffNag){
   
   identite = ++next;
   cout << "Naissance Bestiole (" << identite << ") " << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE * (coeffNageoire / coeffDebuffCarapace);

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

   persoMult = pM;
   taille = t;
   anneesRestantes = a;
   std::cout << "age " << a << "et années restantes " << anneesRestantes << std::endl;

   champOeil = champo;
   champOreille = 2*M_PI;
   distanceOeil = disto;
   distanceOreille = distOr;
   capaciteOeil = capaOeil;
   capaciteOreille = capaOreille;
   coeffCamouflage = coeffCamou;
   coeffCarapace = coeffCarap;
   coeffDebuffCarapace = coeffDebuffCarap;
   coeffNageoire = coeffNag;
    
} 

void Bestiole::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}


void Bestiole::bouge( int xLim, int yLim )
{

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


void Bestiole::action(Milieu & monMilieu)
{

   bouge( monMilieu.getWidth(), monMilieu.getHeight() );

}


void Bestiole::draw( UImg & support )
{

   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;


   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}


bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.identite == b2.identite );

}


bool Bestiole::jeTeVois( const Bestiole & b ) const{
   double dist;
   double angleEntreBestioles;
   double alpha;
   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );

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
         if ((b.x-x)>=0){
            if ((b.y-y)>=0){
               alpha = atan((b.y-y)/(b.x-x));
            } else {
            alpha = atan((b.y-y)/(b.x-x)) + 2*M_PI;
            }
         } else {
            if ((b.y-y)>=0){
               alpha = M_PI_2 + atan((b.y-y)/(b.x-x));
            } else {
            alpha = M_PI + atan((b.y-y)/(b.x-x));
            }
         }
         angleEntreBestioles = abs(orientation - alpha);
         if (angleEntreBestioles<(champOeil/2)){
            return true;
            cout << "je vois"<<endl;
         } else {
            return false;
         }
      }
   }
}

void Bestiole::rebondit()
{
   vitesse*=-1;
}

// Fonction : chechCollision
// Entrée : Deux bestioles
// Sortie : Booléen
// Action : Détermine si deux bestioles se touchent
// (prend en compte la distance entre les deux bestioles, et leur taille).
bool Bestiole::checkCollision(Bestiole* bestiole2){
   int x1 = this->x;
   int x2 = (*bestiole2).getX();
   int y1 = this->y;
   int y2 = (*bestiole2).getY();
   int taille1 = this->taille;
   int taille2 = (*bestiole2).getTaille();

   int distanceCarre = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
   return (distanceCarre < ((((taille1)/2) + ((taille2)/2))*(((taille1)/2) + ((taille2)/2))));
}

// Fonction : collision
// Entrée : Une bestiole
// Sortie : Rien
// Action : Détermine si une bestiole meurt suite à une collision
// (prend en compte la carapace de la bestiole).
// Si la bestiole ne meurt pas, elle rebondie.
bool Bestiole::collision(){
   double carap = this->coeffCarapace;
   double probaMort = (std::rand()/RAND_MAX)/carap;
   return (probaMort > 0.5);
}


Bestiole* Bestiole::clone()
{
   Bestiole* clone = new Bestiole();
   clone->next=next;
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

// Ici on prend tout les arguments de la bestiole donnée en entrée
void Bestiole::clone(Bestiole* bestiolePrototype)
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

bool Bestiole::hasOreille()
{
   return capaciteOreille!=0;
}

bool Bestiole::hasOeil()
{
   return capaciteOeil!=0;
}

bool Bestiole::isPersoMult(){
   return persoMult;
}

void Bestiole::vieillit()
{
   anneesRestantes = anneesRestantes - 1;
}

int Bestiole::getX()
{
   return x;
}

int Bestiole::getY()
{
   return y;
}

double Bestiole::getOrientation()
{
   return orientation;
}

double Bestiole::getVitesse()
{
   return vitesse;
}
int Bestiole::getIdentite()
{
   return identite;
}

int Bestiole::getAnneesRestantes()
{
   return anneesRestantes;
}
int Bestiole::getTaille()
{
   return taille;
}
void Bestiole::setVitesse(double v)
{
   vitesse = v;
}
void Bestiole::setOrientation(double o)
{
   orientation = o;
}