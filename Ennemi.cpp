#include "Ennemi.h"
using namespace std;



Ennemi::Ennemi (){
    _perso = Personnage () ;
}

Ennemi::Ennemi (int x, int  y, Image& i, int d,int skinx, int skiny, int animation , Niveau niveau )     ///Q.13
{
    _perso = Personnage ( x, y, i,  d, skinx,  skiny, animation , niveau ) ;
}

///Q.13
void Ennemi::dessiner () const
{
    _perso.dessiner() ;
}


///Q.23
/*
void Ennemi::avancer ()
{
    // mettre une case pour chaque direction ,
    // faire avancer dans le bon sens jusque  a ce que il puisse plus avancer et la , changer la direction

    switch ( _perso.getdirection() )
    {

    case HAUT :
        if ( _perso.peutBougerVers(HAUT))
            _perso.deplacer(0,-1) ;
        else
            _perso.regarderBas();
        break ;

    case BAS :
        if ( _perso.peutBougerVers(BAS))
            _perso.deplacer(0,1) ;
        else
            _perso.regarderHaut();
        break ;


    case DROITE :
        if ( _perso.peutBougerVers(DROITE))
            _perso.deplacer(1,0) ;
        else
            _perso.regarderGauche();
        break ;

    case GAUCHE :
        if ( _perso.peutBougerVers(GAUCHE))
            _perso.deplacer(-1,0) ;
        else
            _perso.regarderDroite();
        break ;


    default:
        break;
    }
}
*/
///nouvelle version , n'avance plus en ligne mais aleatoirement
void Ennemi::avancer ()
{
    int nombre = rand() % 4 ;
    switch ( nombre )
    {

    case 0 :
        if ( _perso.peutBougerVers(HAUT))
            _perso.deplacer(0,-1) ;
        _perso.regarderHaut() ;
        break ;

    case 1 :
        if ( _perso.peutBougerVers(BAS))
            _perso.deplacer(0,1) ;
        _perso.regarderBas() ;
        break ;


    case 2 :
        if ( _perso.peutBougerVers(DROITE))
            _perso.deplacer(1,0) ;
        _perso.regarderDroite() ;
        break ;

    case 3 :
        if ( _perso.peutBougerVers(GAUCHE))
            _perso.deplacer(-1,0) ;
        _perso.regarderGauche() ;
        break ;


    default:
        break;
    }
}


///Q.25
int Ennemi::getx() const
{
    return _perso.getx() ;
}
int Ennemi::gety() const
{
    return _perso.gety() ;
}





