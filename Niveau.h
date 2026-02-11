#ifndef NIVEAU_H
#define NIVEAU_H
#include <vector>
#include <string>
#include <fstream>
#include "Objet.h"
#include "Dictionnaire.h"

#include <iostream>
using namespace std ;

class Niveau
{

    vector <Objet> _objets ;

public :

    Niveau () ;
    Niveau ( Image& image, const string& nomFichier, Dictionnaire& dico )  ;

    void dessiner () const ;

    bool caseEstLibre ( int x, int y ) ;
};







#endif // NIVEAU_H
