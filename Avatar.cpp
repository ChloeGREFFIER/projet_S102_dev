#include "Avatar.h"
using namespace std;

Avatar::Avatar (){
    _perso = Personnage () ;
}

Avatar::Avatar (int x, int  y, Image& i, int d,int skinx, int skiny, int animation , Niveau niveau )     ///Q.13
{
    _perso = Personnage ( x,  y, i,  d, skinx,  skiny, animation , niveau ) ;
}

///Q.13
void Avatar::dessiner () const
{
    _perso.dessiner() ;

}


///Q.18
void Avatar::allerDroite ()
{
    if ( _perso.peutBougerVers ( DROITE ) )
    {
        _perso.deplacer ( 1, 0 ) ;
    }
    _perso.regarderDroite();
}

void Avatar::allerGauche ()
{
    if ( _perso.peutBougerVers ( GAUCHE ) )
    {
        _perso.deplacer ( -1, 0) ;
    }
    _perso.regarderGauche();
}

void Avatar::allerHaut ()
{
    if ( _perso.peutBougerVers ( HAUT ) )
    {
        _perso.deplacer (0, -1) ;
    }
    _perso.regarderHaut();
}

void Avatar::allerBas ()
{
    if ( _perso.peutBougerVers ( BAS ) )
    {
        _perso.deplacer (0, 1) ;
    }
    _perso.regarderBas();
}






///Q.25
bool Avatar::touche(const Ennemi& e ) const
{
    return ( e.getx() == _perso.getx() && e.gety() == _perso.gety() ) ;
}
