/**
 * @file jouerJoueur.cpp
 * @author Rafael Masson - Arthur Baros
 * @brief Partie du corps du module spellwar.h
 * @date 2023-12-07
 */
#include "spellwar.h"
#include <iostream>

//****************************************************************************
// DECLARATION DES SOUS-PROGRAMMES
//****************************************************************************
/**
 * @brief Permet de faire monter le joueur du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] iLigne l'indice de la ligne de l'element
 * @param [in] iColonne l'indice de la colonne de l'element
 */
void joueurMonter(Spellwar &grille, unsigned int iLigne, unsigned int iColonne);

/**
 * @brief Permet de faire descendre le joueur du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] iLigne l'indice de la ligne de l'element
 * @param [in] iColonne l'indice de la colonne de l'element
 */
void joueurDescendre(Spellwar &grille, char actionJ, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/**
 * @brief Permet de faire tirer un eclair au joueur du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] iLigne l'indice de la ligne de l'element
 * @param [in] iColonne l'indice de la colonne de l'element
 */
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
    ElementDeJeu elementSuivant;

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
    ElementDeJeu elementSuivant;

    elementSuivant = grille.zoneJeu[iLigne + 1][iColonne];

    if (elementSuivant.entite == espaceVide)
    {
        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne + 1, iColonne, creerJoueur(true));
    }
    else if (elementSuivant.entite == necrogriffe)
    {
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
        deplacerFlamme(grille, iLigne + 1, iColonne, adversairesViv);
        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne + 1, iColonne, creerJoueur(true));
    }
}

void joueurEclair(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
{
    ElementDeJeu elementSuivant;

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
        deplacerEclair(grille, iLigne, iColonne + 1, adversairesViv);
        definirElement(grille, iLigne, iColonne + 1, creerEclair(true));
    }
}