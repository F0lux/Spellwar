/**
 * @file creerJoueurEnnemi.cpp
 * @author Rafael Masson - Arthur Baros
 * @brief Partie du corps du module spellwar.h
 * @date 2023-12-07
 */
#include "spellwar.h"

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
void reinitialiserDeplaceCeTour(Spellwar &grille)
{
    for (unsigned int indiceLigne = 0; indiceLigne < TAILLE_COLONNES; indiceLigne++)
    {
        for (unsigned int indiceColonne = 0; indiceColonne < TAILLE_LIGNES; indiceColonne++)
        {
            grille.zoneJeu[indiceLigne][indiceColonne].deplaceCeTour = false;
        }
    }
}