#include "Dictionnaire.h"
using namespace std ;




Dictionnaire::Dictionnaire ()
{
    _lesTuiles = {} ;
}


Dictionnaire::Dictionnaire ( const string& nomFichier )
{

    ifstream input;
    int nblig ;
    string nom ;
    int x ;
    int y ;
    string propriete ;
    Tuile tuile ;

    input.open(nomFichier);
    if(!(input.is_open())) throw(nomFichier);

    input>>nblig;
    for ( int i = 0 ; i<nblig ; i++  )
    {
        input >> nom >> x >> y >> propriete ;
        tuile  = Tuile(nom,  x,  y, propriete ) ;

        _lesTuiles.push_back(tuile);
    }
    input.close();
}




void Dictionnaire::afficher () const
{
    for ( int i = 0 ; i<_lesTuiles.size() ; i++ )
        _lesTuiles[i].afficher() ;
}



bool Dictionnaire::recherche(const string nom, Tuile& result)    ///recherche dichotomique car le tableau est trié
{
    int debut = 0 ;
    int fin = _lesTuiles.size()-1  ;
    int milieu ;
    bool trouve = false ;

    while (!trouve && debut <= fin )
    {
        milieu = ( debut + fin )/2 ;
        trouve = _lesTuiles[milieu].getnom() == nom ;

        if  ( trouve )
            result = _lesTuiles[milieu] ;
        else if ( _lesTuiles[milieu].getnom() > nom )
            fin = milieu - 1 ;
        else
            debut = milieu + 1 ;
    }


    return trouve ;

}








