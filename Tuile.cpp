#include "Tuile.h"
using namespace std ;


Tuile::Tuile ()
{
    _nom = "nom" ;
    _x = 0 ;
    _y = 0 ;
    _propriete = "propriete";
}

Tuile::Tuile (const string& nom, int x, int y, const string& propriete )
{
    _nom = nom ;
    _x = x ;
    _y = y ;
    _propriete  = propriete ;
}

void Tuile::afficher () const
{
    cout<<_nom<< " : "<<endl ;
    cout<<" x : "<<_x<<endl ;
    cout<<" y : "<<_y<<endl ;
    cout<<" propriete : "<<_propriete<<endl ;
}




string Tuile::getnom () const
{
    return _nom ;
}

int Tuile::getx () const
{
    return _x ;
}

int Tuile::gety () const
{
    return _y ;
}
string Tuile::getPropriete() const
{
    return _propriete ;
}









