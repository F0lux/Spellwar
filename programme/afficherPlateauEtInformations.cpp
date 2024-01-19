/*
 Programme : afficherPlateauEtInformations.cpp
 But : Partie du corps du module spellwar.h
 Auteurs : Rafael Masson - Arthur Baros
 Date de derniere modification : 18/01/2024
*/
#include "spellwar.h"
#include <iostream>

//****************************************************************************
// DECLARATION DES SOUS-PROGRAMMES
//****************************************************************************

// BUT : Permet d'afficher sur le terminal la representation graphique de l'enregistrement element
void afficherCaseTableau(const ElementDeJeu &element);

// BUT : Permet d'afficher sur le terminal la grille de jeu de spellwar
void afficherZoneJeu(const Spellwar& grille);

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************

void afficherCaseTableau(const ElementDeJeu &element)
{
    afficherTexteEnCouleur(element.representation, element.couleur);
}

void afficherZoneJeu(const Spellwar &grille)
{
    // Variables
    ElementDeJeu elem;

    // Code de la procedure
    cout << endl;
    for (unsigned int indiceLigne = 0; indiceLigne < TAILLE_COLONNES; indiceLigne++)
    {
        for (unsigned int indiceColonne = 0; indiceColonne < TAILLE_LIGNES; indiceColonne++)
        {
            elem = grille.zoneJeu[indiceLigne][indiceColonne];
            afficherCaseTableau(elem);
        }
        cout << endl;
    }
    cout << endl;
}

void afficherPlateauEtInformations(const Spellwar &grille)
{
    // Afficher la zone de jeu
    afficherZoneJeu(grille);

    // Afficher les actions disponibles pour le joueur
    afficherTexteEnCouleur("Actions possibles :", bleu, true);
    afficherTexteEnCouleur("a --> abandonner, m --> monter, d --> descendre, e --> eclair", bleu, true);
}