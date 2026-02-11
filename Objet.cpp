#include "Objet.h"
using namespace std ;


Objet::Objet ()
{
    _x = 0 ;
    _y = 0 ;
    _tuile = Tuile() ;
}

Objet::Objet ( int x, int y, Image& image, string& nom, Dictionnaire& dico )
{
    _x = x ;
    _y = y ;
    _image = image ;
    dico.recherche( nom, _tuile ) ;
}

void Objet::dessiner () const
{
    _image.dessiner( _x*TAILLE_CASE, _y*TAILLE_CASE, _tuile.getx()*TAILLE_CASE, TAILLE_CASE*_tuile.gety(), TAILLE_CASE, TAILLE_CASE ) ;
}


Tuile Objet::getTuile () const {
    return _tuile ;
}

int Objet::getx () const
{
    return _x ;
}


int Objet::gety () const {
    return _y ;
}
