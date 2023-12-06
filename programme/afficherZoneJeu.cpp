/**
 * @file afficherZoneJeu.cpp
 * @author Rafael Masson - Arthur Baros
 * @brief Partie du corps du module spellwar.h
 * @date 2023-12-02
 */
#include "spellwar.h"
#include <iostream>

//****************************************************************************
// DECLARATION DES SOUS-PROGRAMMES
//****************************************************************************
/**
 * @brief Permet d'afficher sur le terminal la representation graphique de l'enregistrement element
 *
 * @param [in] element l'element a afficher.
 */
void afficherCaseTableau(ElementDeJeu element);

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
void afficherCaseTableau(ElementDeJeu element)
{
    afficherTexteEnCouleur(element.representation, element.couleur);
}

void afficherZoneJeu(Spellwar grille)
{
    // Variables locales
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