/*
 Programme : jouerJoueur.cpp
 But : Partie du corps du module spellwar.h
 Auteurs : Rafael Masson - Arthur Baros
 Date de derniere modification : 18/01/2024
*/
#include "spellwar.h"

//****************************************************************************
// DECLARATION DES SOUS-PROGRAMMES
//****************************************************************************

/* Permet de faire monter d'une ligne le joueur du jeu spellwar
 * Prend en parametre la grille de jeu a modifier,
 * iLigne l'indice de la ligne de l'element et iColonne l'indice de la colonne de l'element */
void joueurMonter(Spellwar &grille, unsigned int iLigne, unsigned int iColonne);

/* Permet de faire descendre d'une ligne le joueur du jeu spellwar
 * Prend en parametre la grille de jeu a modifier, actionJ l'action du joueur, iLigne l'indice de la ligne de l'element,
 * iColonne l'indice de la colonne de l'element et adversairesViv le nombre d'adversaires encore en vie*/
void joueurDescendre(Spellwar &grille, char actionJ, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/* Permet de faire tirer un eclair au joueur du jeu spellwar
 * Prend en parametre la grille de jeu a modifier, iLigne l'indice de la ligne de l'element,
 * iColonne l'indice de la colonne de l'element et adversairesViv le nombre d'adversaires encore en vie*/
void joueurEclair(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************

void jouerJoueur(Spellwar &grille, char actionJ, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
{
    switch (actionJ)
    {
    case 'a':
        definirFinJeu(grille, abandon);
        break;
    case 'm':
        joueurMonter(grille, iLigne, iColonne);
        break;
    case 'd':
        joueurDescendre(grille, actionJ, iLigne, iColonne, adversairesViv);
        break;
    case 'e':
        joueurEclair(grille, iLigne, iColonne, adversairesViv);
        break;
    default:
        break;
    }
}

void joueurMonter(Spellwar &grille, unsigned int iLigne, unsigned int iColonne)
{
    // Variables
    ElementDeJeu elementSuivant;

    // Code de la procedure
    elementSuivant = grille.zoneJeu[iLigne - 1][iColonne];

    if (elementSuivant.entite == espaceVide)
    {
        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne - 1, iColonne, creerJoueur(true));
    }
    else if (elementSuivant.entite == necrogriffe)
    {
        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirFinJeu(grille, mortJoueur);
    }
    else if (elementSuivant.entite == flamme)
    {
        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne - 1, iColonne, creerMarqueurCollision());
        definirFinJeu(grille, mortJoueur);
    }
}

void joueurDescendre(Spellwar &grille, char actionJ, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
{
    // Variables
    ElementDeJeu elementSuivant;

    // Code de la procedure
    elementSuivant = grille.zoneJeu[iLigne + 1][iColonne];

    if (elementSuivant.entite == espaceVide)
    {
        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne + 1, iColonne, creerJoueur(true));
    }
    else if (elementSuivant.entite == necrogriffe)
    {
        /* comme le necrogriffe est en dessous, il n'a pas encore ete deplace, pour faire apparaitre descendre
        le joueur a cette position on doit d'abord deplacer le necrogriffe */
        jouerNecrogriffe(grille, actionJ, iLigne + 1, iColonne, adversairesViv);

        definirElement(grille, iLigne, iColonne, creerEspaceVide());

        if (elementSuivant.entite == necrogriffe)
        {
            definirFinJeu(grille, mortJoueur);
        }
        else
        {
            definirElement(grille, iLigne + 1, iColonne, creerJoueur(true));
        }
    }
    else if (elementSuivant.entite == flamme)
    {
        /* comme la flamme est en dessous, elle n'a pas encore ete deplace, pour faire apparaitre descendre
        le joueur a cette position on doit d'abord deplacer la flamme */
        deplacerFlamme(grille, iLigne + 1, iColonne, adversairesViv);
        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne + 1, iColonne, creerJoueur(true));
    }
}

void joueurEclair(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
{
    // Variables
    ElementDeJeu elementSuivant;

    // Code de la procedure
    elementSuivant = grille.zoneJeu[iLigne][iColonne + 1];

    if (elementSuivant.entite == espaceVide)
    {
        definirElement(grille, iLigne, iColonne + 1, creerEclair(true));
    }
    else if (elementSuivant.entite == necrogriffe || elementSuivant.entite == flamme)
    {
        if (elementSuivant.entite == necrogriffe)
        {
            adversairesViv--;
        }

        definirElement(grille, iLigne, iColonne + 1, creerMarqueurCollision());
    }
    else if (elementSuivant.entite == eclair)
    {
        // comme l'eclair est a droite, il n'a pas encore ete deplace, pour faire apparaitre un eclair a cette position on doit d'abord deplace celui qui s'y trouve deja
        deplacerEclair(grille, iLigne, iColonne + 1, adversairesViv);
        definirElement(grille, iLigne, iColonne + 1, creerEclair(true));
    }
}