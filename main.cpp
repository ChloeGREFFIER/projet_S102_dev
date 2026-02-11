#include <iostream>
#include <vector>
#include <string>

#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"
#include "Avatar.h"
#include "Ennemi.h"
#include "Dictionnaire.h"
#include "Objet.h"
#include "Niveau.h"

using namespace std;




int main(int, char**) // Version special du main, ne pas modifier
{
    // Initialisation du jeu
    Moteur moteur("Mon super jeu vidéo");

    /*
    int y=0;
    int x=0;
    bool directiony = 1;
    bool directionx = 1;
    bool touche_haut = true;
    bool touche_bas= false;
    bool touche_gauche= true;
    bool touche_droite= false;
    */
    Image fond ;
    Image perso ;
    Image objet ;
    Dictionnaire dico  ;
    Niveau niveau ;
    /*
    Image coffre_ferme; //qst 4)
    Image coffre_ouvert; //qst 5)
    Image coffre;*/





    //charger images
    try
    {
        fond = Image( moteur,  "assets/fond.png");
        objet = Image( moteur,  "assets/objets.png");
        dico = Dictionnaire( "assets/dictionnaire.txt" );
        /*coffre_ferme = Image(moteur,  "assets/coffre_ferme.png");
        coffre_ouvert = Image(moteur,  "assets/coffre_ouvert.png");*/

        //perso = Image( moteur,  "assets/personnage_simple.png");
        perso = Image( moteur,  "assets/personnages.png");
        niveau = Niveau ( objet, "assets/niveau.txt", dico ) ;

    }
    catch (runtime_error  &e)
    {
        cerr<<e.what()<<endl;
    }

    ///tests pour dictionnaire
    dico.afficher() ;
    Tuile result ;
    Tuile result1 ;
    Tuile result2 ;
    Tuile result3 ;
    cout<<endl ;
    cout<<"----------------------------------------test pour le dictionnaire ---------------------------"<<endl ;
    cout<<endl ;
    if (dico.recherche( "Torche_1", result))
    {
        cout<<"la recherche marche lorsque la valeure est dans le tableau , la tuile renvoye est : "<<endl ;
        result.afficher () ;
    }
    if (dico.recherche( "Arbre_1", result1))
    {
        cout<<"la recherche marche lorsque la valeure est au debut du tableau , la tuile renvoye est : "<<endl ;
        result1.afficher () ;
    }
    if (dico.recherche( "Village", result2))
    {
        cout<<"la recherche marche lorsque la valeure est a la fin du tableau , la tuile renvoye est : "<<endl ;
        result2.afficher () ;
    }
    if (!dico.recherche( "test_pas_dans_le_dictionnaire", result3))
    {
        cout<<"la recherche marche lorsque la valeure n'est pas dans le tableau , la tuile renvoye est : "<<endl ;
        result3.afficher () ; // affiche une Tuile vide
    }



    //creer persos
    Avatar Gertrudette ( 3 , 3 , perso, BAS, 7, 4,0 ,niveau) ;
    //Gertrudette.regarderDroite();// test pour question 6
    Ennemi ennemi1 ( 5, 2 , perso, BAS, 9, 0, 0 , niveau ) ;
    Ennemi ennemi2( 1, 5, perso, DROITE, 9, 0, 0 , niveau ) ;











    bool quitter = false;
    //bool coffre_est_ferme= true;
    // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
    // (en general, 60 fois par seconde)
    while (!quitter)
    {
        // I. Gestion des evenements
        Evenement evenement = moteur.evenementRecu();
        while (evenement != AUCUN)
        {
            switch (evenement)
            {
            // QUITTER = croix de la fenetre ou Echap
            case QUITTER_APPUYE: //qst 5)
                quitter = true;
                break;

            // TODO: gerer les autres evenements
            /*
            case ESPACE_APPUYE :
                coffre_est_ferme = false;
                break;

            case ESPACE_RELACHE : // qst 6)
                coffre_est_ferme = true;
                break;
            */
            ///Q.8
            /*
            case GAUCHE_APPUYE :
                Gertrudette.regarderGauche();
                break;
            case DROITE_APPUYE :
                Gertrudette.regarderDroite();
                break;
            case HAUT_APPUYE :
                Gertrudette.regarderHaut();
                break;
            case BAS_APPUYE :
                Gertrudette.regarderBas();
                break;
            */
            ///Q.19

            case GAUCHE_APPUYE :
                Gertrudette.allerGauche();
                break;
            case DROITE_APPUYE :
                Gertrudette.allerDroite();
                break;
            case HAUT_APPUYE :
                Gertrudette.allerHaut();
                break;
            case BAS_APPUYE :
                Gertrudette.allerBas();
                break;
            default:
                break;
            }
            evenement = moteur.evenementRecu();
        }





// II. Mise à jour de l'état du jeu

        if (moteur.animationsAmettreAjour())
        {
            ennemi1.avancer() ;
            ennemi2.avancer() ;
        }


        if (Gertrudette.touche(ennemi1) || Gertrudette.touche(ennemi2))
        {
            quitter = true ;
            moteur.attendre (3) ;
        }



        /*
        if (coffre_est_ferme)
        {
            coffre= coffre_ferme ;
        }

        else
        {
            coffre= coffre_ouvert ;

        }
        */


// TODO: faire bouger vos personnages, etc.

// III. Generation de l'image à afficher

        moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir
        //fond.dessiner (0,0) ;
        niveau.dessiner() ;

// TODO: afficher vos personnages, objets, etc.
        Gertrudette.dessiner();
        ennemi1.dessiner();
        ennemi2.dessiner();












        /* Q.8
        fond.dessiner (0,0);// qst.3)
        //coffre_ferme.dessiner (0,0); //qst 4)
        coffre.dessiner (x,y); // qst 5)
        coffre.dessiner (x,y);

        if (y> fond.getHauteur()) //qst 7)
        {
            y=0; // qst 8)

        }
        else
        {
            y++;
        }
        */
        moteur.finaliserRendu();

    }

    return 0;
}


