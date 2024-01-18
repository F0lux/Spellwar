//****************************************************************************
// EN-TETE
//****************************************************************************
/*
 Programme : Spellwar
 But du jeu :
 Regles du jeu :
 Date de dernière modification : 09 janvier 2023
 Auteur : R. Masson et A. Baros
 Remarques : Code conforme aux spécification internes donnees en cours
 Resultat du test :
*/

//****************************************************************************
// INCLUSION
//****************************************************************************
#include <iostream>
#include "game-tools.h"
#include "spellwar.h"
using namespace std;

//****************************************************************************
// PROGRAMME PRINCIPAL
//****************************************************************************
int main(void)
{
    // VARIABLES
    Spellwar plateauJeu;           // Grille du jeu
    bool partieFinie;              // Vrai si une condition de fin de partie a ete atteinte
    string actionsSaisieParJ;      // Chaine de caractere contenant les actions saisies par le joueur
    char actionCourante;           // Caractere contenant l'action courante du joueur
    unsigned int adversairesEnVie; // Nombre d'aversaires en vie

    // INITIALISER LA PARTIE

    // Initialiser les variables
    // Initialiser le nombre d'aversaire en vie
    adversairesEnVie = NOMBRES_ADVERSAIRES;
    // Initialiser l'indicateur de fin de partie
    partieFinie = false;

    // Initialiser le tableau
    creerZoneJeu(plateauJeu);

    // Positionner le joueur et les adversaires
    positionnerPersonnages(plateauJeu);

    // JOUER LA PARTIE
    do
    {
        // Afficher la zone de jeu et les actions possibles
        afficherPlateauEtInformations(plateauJeu);

        // Saisir les actions
        cout << "Vos actions : ";
        cin >> actionsSaisieParJ;

        effacer();
        // Jouer toutes les actions et verifier si la partie est finie
        for (unsigned int indiceAction = 0; indiceAction < static_cast<unsigned int>(actionsSaisieParJ.size()); indiceAction++)
        {
            // Affecter a actionCourante l'action courante de la saisie du joueur
            actionCourante = actionsSaisieParJ[indiceAction];

            // Jouer un tour
            jouerUnTour(plateauJeu, actionCourante, adversairesEnVie);

            // Afficher la zone de jeu et les actions possibles
            afficherPlateauEtInformations(plateauJeu);
            // Afficher les actions que le joueur a saisi
            cout << "Vos actions : " << actionsSaisieParJ << endl
                 << endl;

            // Supprimer les marques de collision
            supprimerMarqueCollision(plateauJeu);

            // Tester si la partie est finie
            if (obtenirFinJeu(plateauJeu) == abandon)
            {
                partieFinie = true;
                break;
            }
            if (obtenirFinJeu(plateauJeu) == mortJoueur)
            {
                partieFinie = true;
                break;
            }
            if (adversairesEnVie == 0)
            {
                definirFinJeu(plateauJeu, victoireJoueur);
                partieFinie = true;
                break;
            }
            pause(1);
            effacer();

            // Remettre tout les indicateurs deplaceCeTour des cases de plateauJeu a faux
            reinitialiserDeplacements(plateauJeu);
        }
    } while (!partieFinie);

    // FINIR LA PARTIE
    finirLaPartie(plateauJeu);

    return 0;
}