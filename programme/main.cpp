//****************************************************************************
// EN-TETE
//****************************************************************************
/*
 Programme : Spellwar
 But du jeu :
 Regles du jeu :
 Date de dernière modification : 02 decembre 2023
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
// DEFINITION DES TYPES
//****************************************************************************
/*enum ElementDeJeu
{
    espaceVide,
    murVertical,
    murHorizontal,
    joueur,
    eclair,
    arcaflamme,
    flamme,
    necrogriffe
};*/

//****************************************************************************
// DECLARATION DES SOUS-PROGRAMMES
//****************************************************************************


//****************************************************************************
// PROGRAMME PRINCIPAL
//****************************************************************************
int main(void)
{
    // VARIABLES
    Spellwar plateauJeu; // Grille du jeu

    string actionsSaisieParJ; // Chaine de caractere contenant les actions saisies par le joueur
    char actionCourante;
    unsigned int adversairesEnVie;

    // Initialiser la partie
    // Initialiser les variables (NOM DES VARIABLES DANS LE COMMENTAIRE)
    adversairesEnVie = NOMBRES_ADVERSAIRES;

    // Initialiser le tableau
    creerZoneJeu(plateauJeu);

    // Positionner le joueur et les adversaires
    positionnerJoueurEnnemi(plateauJeu);

    // Jouer la partie
    while (true)
    {
        
        // Saisir et jouer le(s) action(s)
        while (true)
        {
            // Afficher la zone de jeu
            afficherZoneJeu(plateauJeu);

            // Supprimer les marques de collision
            supprimerMarqueCollision(plateauJeu);

            // Afficher les actions disponibles pour le joueur
            afficherTexteEnCouleur("Actions possibles :", bleu, true);
            afficherTexteEnCouleur("a --> abandonner, m --> monter, d --> descendre, e --> eclair", bleu, true);

            // Saisir les actions
            cout << "Vos actions : ";
            cin >> actionsSaisieParJ;
            
            // Jouer les actions
            for (unsigned int indiceAction = 0; indiceAction < static_cast<unsigned int>(actionsSaisieParJ.size()); indiceAction++)
            {
                for (unsigned int indiceLigne = 0; indiceLigne < TAILLE_COLONNES; indiceLigne++)
                {
                    for (unsigned int indiceColonne = 0; indiceColonne < TAILLE_LIGNES; indiceColonne++)
                    {
                        actionCourante = actionsSaisieParJ[indiceAction];
                        if (plateauJeu.zoneJeu[indiceLigne][indiceColonne].representation == 'J' && plateauJeu.zoneJeu[indiceLigne][indiceColonne].deplaceCeTour == false)
                        {
                            actionJoueur(plateauJeu,actionCourante,indiceLigne,indiceColonne,adversairesEnVie);
                        }
                        else if (plateauJeu.zoneJeu[indiceLigne][indiceColonne].representation == 'A' && plateauJeu.zoneJeu[indiceLigne][indiceColonne].deplaceCeTour == false)
                        {
                            actionArcaflamme(plateauJeu,indiceLigne,indiceColonne,adversairesEnVie);
                        }
                        else if (plateauJeu.zoneJeu[indiceLigne][indiceColonne].representation == 'N' && plateauJeu.zoneJeu[indiceLigne][indiceColonne].deplaceCeTour == false)
                        {
                            actionNecrogriffe(plateauJeu,actionCourante,indiceLigne,indiceColonne,adversairesEnVie);
                        }
                    }
                }
            reinitialiserDeplacements(plateauJeu);
            effacer();
            }
        }
    }
    // Finir la partie
    return 0;
}

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
