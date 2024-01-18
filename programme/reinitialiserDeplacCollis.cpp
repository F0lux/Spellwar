/**
 * @file reinitialiserDeplacCollis.cpp
 * @author Rafael Masson - Arthur Baros
 * @brief Partie du corps du module spellwar.h
 * @date 2023-12-07
 */
#include "spellwar.h"

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
            if (grille.zoneJeu[indiceLigne][indiceColonne].entite == marqueurCollision && indiceColonne == 0)
            {
                if (indiceColonne == 0)
                {
                    grille.zoneJeu[indiceLigne][indiceColonne] = creerMurVertical();
                }
                else
                {
                    grille.zoneJeu[indiceLigne][indiceColonne] = creerEspaceVide();
                }
            }
        }
    }
}