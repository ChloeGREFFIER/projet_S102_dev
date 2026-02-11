#ifndef AVATAR_H
#define AVATAR_H
#include "Personnage.h"
#include "Ennemi.h"

#include <iostream>
using namespace std ;



class Avatar
{

    Personnage _perso;

public :

    Avatar () ;
    Avatar (int x, int  y, Image& i, int d,int skinx, int skiny, int animation , Niveau niveau  ) ;   ///Q.13

    ///Q.13
    void dessiner () const ;
    ///Q.18
    void allerDroite () ;
    void allerGauche () ;
    void allerHaut () ;
    void allerBas () ;

    ///Q.25
    bool touche (const Ennemi& e ) const ;



};












#endif // AVATAR_H
