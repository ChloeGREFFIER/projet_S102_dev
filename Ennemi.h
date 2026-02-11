#ifndef ENNEMI_H
#define ENNEMI_H
#include "Personnage.h"

#include <iostream>
using namespace std ;



class Ennemi
{

    Personnage _perso;

public :

    Ennemi () ;
    Ennemi (int x, int  y, Image& i, int d,int skinx, int skiny, int animation , Niveau niveau ) ;   ///Q.13

    ///Q.13
    void dessiner () const ;

    ///Q.23
    void avancer () ;

    ///Q.25
    int getx() const  ;
    int gety() const  ;



};






#endif // ENNEMI_H
