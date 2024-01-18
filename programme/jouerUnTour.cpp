/**
 * @file jouerUnTour.cpp
 * @author Rafael Masson - Arthur Baros
 * @brief Partie du corps du module spellwar.h
 * @date 2023-01-17
 */
#include "spellwar.h"
#include <iostream>

void jouerUnTour(Spellwar &grille, char actionJ, unsigned int &adversairesViv)
{
    for (unsigned int indiceLigne = 0; indiceLigne < TAILLE_COLONNES; indiceLigne++)
    {
        for (unsigned int indiceColonne = 0; indiceColonne < TAILLE_LIGNES; indiceColonne++)
        {
            if (estJoueurPasDeplCeTour(grille, indiceLigne, indiceColonne))
            {
                jouerJoueur(grille, actionJ, indiceLigne, indiceColonne, adversairesViv);
            }
            else if (estArcaflammePasDeplCeTour(grille, indiceLigne, indiceColonne))
            {
                jouerArcaflamme(grille, indiceLigne, indiceColonne, adversairesViv);
            }
            else if (estNecrogriffePasDeplCeTour(grille, indiceLigne, indiceColonne))
            {
                jouerNecrogriffe(grille, actionJ, indiceLigne, indiceColonne, adversairesViv);
            }
            else if (estEclairPasDeplCeTour(grille, indiceLigne, indiceColonne))
            {
                deplacerEclair(grille, indiceLigne, indiceColonne, adversairesViv);
            }
            else if (estFlammePasDeplCeTour(grille, indiceLigne, indiceColonne))
            {
                deplacerFlamme(grille, indiceLigne, indiceColonne, adversairesViv);
            }
        }
    }
}
