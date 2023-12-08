/**
 * @file reinitialiserDeplacCollis.cpp
 * @author Rafael Masson - Arthur Baros
 * @brief Partie du corps du module spellwar.h
 * @date 2023-12-07
 */
#include "spellwar.h"

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
void reinitialiserDeplacements(Spellwar &grille)
{
    for (unsigned int indiceLigne = 0; indiceLigne < TAILLE_COLONNES; indiceLigne++)
    {
        for (unsigned int indiceColonne = 0; indiceColonne < TAILLE_LIGNES; indiceColonne++)
        {
            grille.zoneJeu[indiceLigne][indiceColonne].deplaceCeTour = false;
        }
    }
}

void supprimerMarqueCollision(Spellwar &grille)
{
    for (unsigned int indiceLigne = 0; indiceLigne < TAILLE_COLONNES; indiceLigne++)
    {
        for (unsigned int indiceColonne = 0; indiceColonne < TAILLE_LIGNES; indiceColonne++)
        {
            if (grille.zoneJeu[indiceLigne][indiceColonne].representation == 'X' && indiceColonne == 0)
            {
                grille.zoneJeu[indiceLigne][indiceColonne] = {'|', cyan, false};
            }
            else if (grille.zoneJeu[indiceLigne][indiceColonne].representation == 'X' && indiceColonne != 0)
            {
                grille.zoneJeu[indiceLigne][indiceColonne] = {' ', blanc, false};
            }
        }
    }
}