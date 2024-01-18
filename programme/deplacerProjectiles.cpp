/**
 * @file deplacerProjectiles.cpp
 * @author Rafael Masson - Arthur Baros
 * @brief Partie du corps du module spellwar.h
 * @date 2023-01-18
 */
#include "spellwar.h"

void deplacerEclair(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
{
    ElementDeJeu elementSuivant;

    elementSuivant = grille.zoneJeu[iLigne][iColonne + 1];

    if (elementSuivant.entite == espaceVide || elementSuivant.entite == eclair)
    {
        if (elementSuivant.entite == eclair)
        {
            deplacerEclair(grille, iLigne, iColonne + 1, adversairesViv);
        }

        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne, iColonne + 1, creerEclair(true));
    }
    else if (elementSuivant.entite == flamme || elementSuivant.entite == necrogriffe || elementSuivant.entite == arcaflamme)
    {
        if (elementSuivant.entite == necrogriffe || elementSuivant.entite == arcaflamme)
        {
            adversairesViv--;
        }

        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne, iColonne + 1, creerMarqueurCollision());
    }
    else if (estSurDerniereColonne(iColonne))
    {
        definirElement(grille, iLigne, iColonne, creerEspaceVide());
    }
}

void deplacerFlamme(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
{
    ElementDeJeu elementSuivant;

    elementSuivant = grille.zoneJeu[iLigne][iColonne - 1];

    if (elementSuivant.entite == espaceVide)
    {
        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne, iColonne - 1, creerFlamme(true));
    }
    else if (elementSuivant.entite == murVertical || elementSuivant.entite == eclair || elementSuivant.entite == necrogriffe || elementSuivant.entite == joueur)
    {
        if (elementSuivant.entite == necrogriffe)
        {
            adversairesViv--;
        }
        else if (elementSuivant.entite == joueur)
        {
            definirFinJeu(grille, mortJoueur);
        }

        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne, iColonne - 1, creerMarqueurCollision());
    }
}