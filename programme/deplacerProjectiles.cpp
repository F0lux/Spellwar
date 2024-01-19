/*
 Programme : deplacerProjectiles.cpp
 But : Partie du corps du module spellwar.h
 Auteurs : Rafael Masson - Arthur Baros
 Date de derniere modification : 18/01/2024
*/
#include "spellwar.h"

void deplacerEclair(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
{
    // Variables
    ElementDeJeu elementSuivant;

    // Code de la procedure
    elementSuivant = grille.zoneJeu[iLigne][iColonne + 1];

    if (elementSuivant.entite == espaceVide || elementSuivant.entite == eclair)
    {
        if (elementSuivant.entite == eclair)
        {
            // comme l'eclair est a droite, il n'a pas encore ete deplace, pour faire apparaitre un eclair a cette position on doit d'abord deplace celui qui s'y trouve deja
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
    // Variable
    ElementDeJeu elementSuivant;

    // Code de la procedure
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