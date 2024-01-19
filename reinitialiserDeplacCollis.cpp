/*
 Programme : reinitialiserDeplacCollis.cpp
 But : Partie du corps du module spellwar.h
 Auteurs : Rafael Masson - Arthur Baros
 Date de derniere modification : 18/01/2024
*/
#include "spellwar.h"

void reinitialiserDeplacements(Spellwar &grille)
{
    // Parcours complet de la grille
    for (unsigned int indiceLigne = 0; indiceLigne < TAILLE_COLONNES; indiceLigne++)
    {
        for (unsigned int indiceColonne = 0; indiceColonne < TAILLE_LIGNES; indiceColonne++)
        {
            // Reinitialiser l'indicateur de deplacement a faux
            grille.zoneJeu[indiceLigne][indiceColonne].deplaceCeTour = false;
        }
    }
}

void supprimerMarqueCollision(Spellwar &grille)
{
    // Parcours complet de la grille
    for (unsigned int indiceLigne = 0; indiceLigne < TAILLE_COLONNES; indiceLigne++)
    {
        for (unsigned int indiceColonne = 0; indiceColonne < TAILLE_LIGNES; indiceColonne++)
        {
            // Tester si l'element est un marqueur de collision
            if (grille.zoneJeu[indiceLigne][indiceColonne].entite == marqueurCollision)
            {
                if (estSurPremiereColonne(indiceColonne))
                {
                    // Mettre un murVertical sur l'element courant
                    grille.zoneJeu[indiceLigne][indiceColonne] = creerMurVertical();
                }
                else
                {
                    // Mettre un espaceVide sur l'element courant
                    grille.zoneJeu[indiceLigne][indiceColonne] = creerEspaceVide();
                }
            }
        }
    }
}