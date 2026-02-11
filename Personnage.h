#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <vector>
#include "Image.h"
#include "Niveau.h"

#include <iostream>
using namespace std ;

enum Direction { BAS, GAUCHE, DROITE, HAUT };


class Personnage
{
    int _x ;
    int _y ;
    Image _image ;
    int _direction ;
    int _skinx ;
    int _skiny ;
    int _animation ;
    Niveau _niveau ;


public :

    Personnage ();
    ///Q.1
    Personnage (int x, int  y, Image& i, int d,int skinx, int skiny, int _animation , Niveau niveau);

    ///Q.2
    void dessiner () const ;

    ///Q.6
    void regarderDroite() ;
    void regarderGauche() ;
    void regarderHaut () ;
    void regarderBas () ;

    ///Q.16
    void deplacer(int dx, int dy) ;
    ///Q.20
    bool peutBougerVers (int direction);

    ///Q.23
    int getdirection() const;
    void changeDirection(int dir);

    ///Q.25
    int getx() const ;
    int gety() const ;



};








#endif // PERSONNAGE_H
