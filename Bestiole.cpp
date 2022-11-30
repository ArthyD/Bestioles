#include "Bestiole.h"

#include "Milieu.h"

#include <cstdlib>
#include <cmath>


const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;

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

   //cout << "dest Bestiole" << endl;

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


bool Bestiole::jeTeVois( const Bestiole & b ) const

{

   double         dist;

   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   return ( dist <= LIMITE_VUE );

}

void Bestiole::rebondit(Bestiole * pBestiole)
{
   this->vitesse*=-1;
}

Bestiole Bestiole::clone()
{
   return(Bestiole(*this));
} 

Bestiole Bestiole::clone(Bestiole bestiolePrototype)
{
   return(Bestiole(bestiolePrototype));
} 

bool Bestiole::hasOreille()
{
   return (this->capaciteOreille!=0);
}

bool Bestiole::hasOeil()
{
   return (this->capaciteOeil!=0);
}

void Bestiole::vieillit()
{
   this->anneesRestantes-=1;
}

int Bestiole::getX()
{
   return (this->x);
}

int Bestiole::getY()
{
   return (this->y);
}

double Bestiole::getOrientation()
{
   return (this->orientation);
}

double Bestiole::getVitesse()
{
   return (this->vitesse);
}
int Bestiole::getIdentite()
{
   return (this->identite);
}
void Bestiole::setVitesse(double v)
{
   this->vitesse = v;
}
void Bestiole::setOrientation(double o)
{

   this->orientation = orientation;
}