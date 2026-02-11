#include "Niveau.h"
using namespace std ;


Niveau::Niveau ()
{
    _objets = {} ;
}

Niveau::Niveau ( Image& image, const string& nomFichier, Dictionnaire& dico )
{
    ifstream input;
    int nbobj ;

    string nom ;
    int x ;
    int y ;
    Objet objet ;

    input.open(nomFichier);
    if(!(input.is_open())) throw(nomFichier);

    input>>nbobj;
    for ( int i = 0 ; i<nbobj ; i++  )
    {
        input >> nom >> x >> y ;
        objet  = Objet( x, y, image, nom, dico) ;

        _objets.push_back(objet);
    }
    input.close();
}



void Niveau::dessiner () const
{
    for ( int i = 0 ; i<_objets.size() ; i++ )
        _objets[i].dessiner() ;
}




bool Niveau::caseEstLibre ( int x, int y )
{
    bool libre = true ;
    int i = 0 ;
    while ( libre && i<_objets.size())
    {
        libre = !(_objets[i].getTuile().getPropriete() == "solide" && _objets[i].gety() == y && _objets[i].getx() == x );
        i++ ;
    }
    return libre ;
}







