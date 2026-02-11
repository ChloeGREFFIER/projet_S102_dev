#ifndef TUILE_H
#define TUILE_H
#include <string>

#include <iostream>
using namespace std ;


class Tuile
{

    string _nom ;
    int _x ;    // x et y dans la feuille de sprite
    int _y ;
    string _propriete ;

public :

    Tuile () ;
    Tuile (const string& nom, int x, int y,const  string& propriete ) ;

    void afficher () const ;
    string getnom () const ;
    int getx () const ;
    int gety () const ;
    string getPropriete() const ;


};
















#endif // TUILE_H
