/**
 * @file deplacerProjectiles.cpp
 * @author Rafael Masson - Arthur Baros
 * @brief Partie du corps du module spellwar.h
 * @date 2023-01-17
 */
#include "spellwar.h"

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
void deplacerEclair(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
{
    ElementDeJeu elementCourant;
    ElementDeJeu elementSuivant;

    elementCourant = grille.zoneJeu[iLigne][iColonne];
    elementSuivant = grille.zoneJeu[iLigne][iColonne + 1];

    if (elementSuivant.entite == espaceVide || elementSuivant.entite == eclair)
    {
        if (elementSuivant.entite == eclair)
        {
            deplacerEclair(grille, iLigne, iColonne + 1, adversairesViv);
        }

        elementCourant = creerEspaceVide();
        elementSuivant = creerEclair(true);
    }
    else if (elementSuivant.entite == flamme || elementSuivant.entite == necrogriffe || elementSuivant.entite == arcaflamme)
    {
        if (elementSuivant.entite == necrogriffe || elementSuivant.entite == arcaflamme)
        {
            adversairesViv--;
        }

        elementCourant = creerEspaceVide();
        elementSuivant = creerMarqueurCollision();
    }
    else if (estSurDerniereColonne(iColonne))
    {
        elementCourant = creerEspaceVide();
    }

    grille.zoneJeu[iLigne][iColonne] = elementCourant;
    grille.zoneJeu[iLigne][iColonne + 1] = elementSuivant;
}

void deplacerFlamme(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
{
    ElementDeJeu elementCourant;
    ElementDeJeu elementSuivant;

    elementCourant = grille.zoneJeu[iLigne][iColonne];
    elementSuivant = grille.zoneJeu[iLigne][iColonne - 1];

    if (elementSuivant.entite == espaceVide)
    {
        elementCourant = creerEspaceVide();
        elementSuivant = creerFlamme(true);
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

        elementCourant = creerEspaceVide();
        elementSuivant = creerMarqueurCollision();
    }

    grille.zoneJeu[iLigne][iColonne] = elementCourant;
    grille.zoneJeu[iLigne][iColonne - 1] = elementSuivant;
}