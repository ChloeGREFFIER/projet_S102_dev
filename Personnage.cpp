#include "Personnage.h"
using namespace std;


Personnage::Personnage()
{
    _x = 0;
    _y = 0;
    _direction = BAS;
    _skinx = 0;
    _skiny = 0;
    _animation = 0 ;
    _niveau = Niveau() ;
}

Personnage::Personnage(int x, int  y, Image& i, int d,int skinx, int skiny, int animation , Niveau niveau  )
{
    _x = x*TAILLE_CASE ;
    _y = y*TAILLE_CASE ;
    _image = i ;
    _direction = d ;
    _skinx = skinx ;
    _skiny = skiny ;
    _animation = animation % 2 ; // %2 non necessaire , c'est une verification au cas ou la valeure n'est pas entre 0 et 2
    _niveau = niveau ;
}


void Personnage::dessiner () const
{
    //_image.dessiner(_x , _y ) ;
    _image.dessiner( _x, _y, _skinx*TAILLE_CASE+_animation*TAILLE_CASE, TAILLE_CASE*(_direction+_skiny ), TAILLE_CASE, TAILLE_CASE ) ;
}


void Personnage::regarderDroite()
{
    _direction = DROITE ;
}
void Personnage::regarderGauche()
{
    _direction = GAUCHE  ;
}
void Personnage::regarderHaut ()
{
    _direction = HAUT  ;
}
void Personnage::regarderBas ()
{
    _direction = BAS ;
}

void Personnage::deplacer(int dx, int dy)
{
    _x += dx*TAILLE_CASE ;
    _y += dy*TAILLE_CASE ;
    _animation =  ( _animation+1 )% 2 ;
}

bool Personnage::peutBougerVers (int direction )
{
    bool ok ;
    int posx = (_x/TAILLE_CASE ) ;
    int posy = (_y/TAILLE_CASE ) ;


    switch ( direction )
    {
    case DROITE :
        ok = _x+TAILLE_CASE < LARGEUR_FENETRE && _niveau.caseEstLibre( posx+1 , posy ) ;
        break ;
    case GAUCHE :
        ok = _x-TAILLE_CASE >= 0 && _niveau.caseEstLibre(posx-1 , posy ) ;
        break ;
    case HAUT :
        ok = _y-TAILLE_CASE >= 0 && _niveau.caseEstLibre(posx , posy-1 ) ;
        break ;
    case BAS :
        ok = _y+TAILLE_CASE < HAUTEUR_FENETRE && _niveau.caseEstLibre( posx , posy+1 ) ;
        break ;
    default:
        break;
    }
    return ok ;
}



int Personnage::getdirection()const
{
    return _direction ;
}

int Personnage::getx()const
{
    return _x ;
}
int Personnage::gety()const
{
    return _y ;
}











