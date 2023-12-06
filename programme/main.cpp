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

    // const int NOMBRES_ADVERSAIRES = 3; // Nombre initial d'adversaires

    string actionsSaisieParJ; // Chaine de caractere contenant les actions saisies par le joueur
    cout << "E";
    // Initialiser la partie
    // Initialiser les variables (NOM DES VARIABLES DANS LE COMMENTAIRE)

    // Initialiser le tableau
    creerZoneJeu(plateauJeu);

    // Positionner le joueur
    //plateauJeu.zoneJeu[TAILLE_COLONNES / 2][1] = {'J', cyan, false};

    // Positionner les adversaires
    // Nombre d'arcaflammes/necrogriffes a afficher

    // Positionner le(s) arcaflamme(s) et le(s) necrogriffe(s)

    // Afficher la zone de jeu
    afficherZoneJeu(plateauJeu);

    // Jouer la partie
    while (true)
    {
        
        // Saisir et jouer le(s) action(s)
        while (true)
        {
            // Afficher les actions disponibles pour le joueur
            afficherTexteEnCouleur("Actions possibles :", bleu, true);
            afficherTexteEnCouleur("a --> abandonner, m --> monter, d --> descendre, e --> eclair", bleu, true);

            // Saisir les actions
            cout << "Vos actions : ";
            cin >> actionsSaisieParJ;
            
            // Jouer les actions
            for (unsigned int i = 0; i < static_cast<unsigned int>(actionsSaisieParJ.size()); i++)
            {
                for (unsigned int indiceLigne = 0; indiceLigne < TAILLE_COLONNES; indiceLigne++)
                {
                    for (unsigned int indiceColonne = 0; indiceColonne < TAILLE_LIGNES; indiceColonne++)
                    {
                        if (plateauJeu.zoneJeu[indiceLigne][indiceColonne].representation == 'J' && plateauJeu.zoneJeu[indiceLigne][indiceColonne].deplaceCeTour == false)
                        {
                            // Sur le parcours du tableau, qd on arrive au joueur il faut voir ce qu'il fait
                            /*switch (actionsSaisieParJ[i])
                            {
                            case 'a':
                             
                                break;
                            case 'm':
                            
                                break;
                            case 'd':
                              
                                break;
                            case 'e':
                                break;
                            }*/
                        }
                    }
                }
            }
        }
    }
    // Finir la partie
    return 0;
}

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
