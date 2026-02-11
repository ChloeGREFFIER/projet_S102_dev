#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H
#include <vector>
#include<fstream>
#include "Tuile.h"

#include <iostream>
using namespace std ;

class Dictionnaire
{
    vector<Tuile> _lesTuiles ;

public :

    Dictionnaire () ;
    Dictionnaire ( const string& nomFichier ) ;

    void afficher () const ;
    bool recherche(const string nom, Tuile& result) ;

};












#endif // DICTIONNAIRE_H
