/*
 Programme : jouerUnTour.cpp
 But : Partie du corps du module spellwar.h
 Auteurs : Rafael Masson - Arthur Baros
 Date de derniere modification : 18/01/2024
*/
#include "spellwar.h"

void jouerUnTour(Spellwar &grille, char actionJ, unsigned int &adversairesViv)
{
    // Parcours par element de la grille
    for (unsigned int indiceLigne = 0; indiceLigne < TAILLE_COLONNES; indiceLigne++)
    {
        for (unsigned int indiceColonne = 0; indiceColonne < TAILLE_LIGNES; indiceColonne++)
        {
            // Faire jouer l'element courant 
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
