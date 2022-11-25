#include "Milieu.h"

#include <cstdlib>
#include <ctime>

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}

void Milieu::step( void ){
   
   phaseDetection();
   phaseAction();
   //PhaseEnvironnement();
   naissanceAlea();

}

void Milieu::phaseEnvironnement( void ){

}

void Milieu::naissanceAlea( void ){


}

void Milieu::phaseDetection ( void ){
   std::vector<Bestiole> bestiolesAlentours;
   for ( std::list<Bestiole>::iterator it1 = listeBestioles.begin() ; it1 != listeBestioles.end() ; ++it1 )
   {
      for ( std::list<Bestiole>::iterator it2 = listeBestioles.begin() ; it2 != listeBestioles.end() ; ++it2 ){
         if (it1 != it2) {
               bool verif = it1->jeTeVois(*it2);
               if (verif) {
                  bestiolesAlentours.push_back(*it2);
               }
               it1->update(bestiolesAlentours);
         }
      bestiolesAlentours.clear();
      }
      }
}

void Milieu::phaseAction( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::list<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {

      it->action( *this );
      it->draw( *this );

   } 

}


int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::list<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}
