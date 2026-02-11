#ifndef OBJET_H
#define OBJET_H
#include "Image.h"
#include "Tuile.h"
#include "Dictionnaire.h"

#include <iostream>
using namespace std ;

class Objet
{

    int _x ;    // coordonnées x et y a l'ecran
    int _y ;
    Image _image ;
    Tuile _tuile ;

public :

    Objet () ;
    Objet ( int x, int y, Image& image, string& nom, Dictionnaire& dico);

    void dessiner () const ;
    Tuile getTuile () const ;
    int getx () const ;
    int gety () const ;
};














#endif // OBJET_H
