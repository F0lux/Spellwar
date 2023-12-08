/**
 * @file actionJoueur.cpp
 * @author Rafael Masson - Arthur Baros
 * @brief Partie du corps du module spellwar.h
 * @date 2023-12-07
 */
#include "spellwar.h"
#include <iostream>

//****************************************************************************
// DECLARATION DES SOUS-PROGRAMMES
//****************************************************************************
void joueurMonter(Spellwar &grille, unsigned int iLigne, unsigned int iColonne);

void joueurDescendre(Spellwar &grille, unsigned int iLigne, unsigned int iColonne);

void joueurEclair(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv);

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
void actionJoueur(Spellwar &grille, char actionJ, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv)
{
    switch (actionJ)
    {
    case 'a':
        grille.finJeu = abandon;
        break;
    case 'm':
        joueurMonter(grille,iLigne,iColonne);
        break;
    case 'd':
        joueurDescendre(grille,iLigne,iColonne);
        break;
    case 'e':
        joueurEclair(grille,iLigne,iColonne,adversairesViv);
        if (adversairesViv == 0)
        {
            grille.finJeu = mortAdversaires;
        }
        break;
    default:
        break;
    }
}

void joueurMonter(Spellwar &grille, unsigned int iLigne, unsigned int iColonne)
{
    if (grille.zoneJeu[iLigne - 1][iColonne].representation == ' ')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne - 1][iColonne] = {'J', cyan, true};
    }
    else if (grille.zoneJeu[iLigne - 1][iColonne].representation == 'N')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.finJeu = mortJoueur;
    }
    else if (grille.zoneJeu[iLigne - 1][iColonne].representation == '<')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne - 1][iColonne] = {' ', blanc, false};
        grille.finJeu = mortJoueur;
    }
    // pas de else pour la flamme car il y a le cas ou l'element rencontre est un murHorizontal
}

void joueurDescendre(Spellwar &grille, unsigned int iLigne, unsigned int iColonne)
{
    if (grille.zoneJeu[iLigne + 1][iColonne].representation == ' ')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne + 1][iColonne] = {'J', cyan, true};
    }
    else if (grille.zoneJeu[iLigne + 1][iColonne].representation == 'N')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.finJeu = mortJoueur;
    }
    else if (grille.zoneJeu[iLigne + 1][iColonne].representation == '<')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne + 1][iColonne] = {' ', blanc, false};
        grille.finJeu = mortJoueur;
    }
    // pas de else pour la flamme car il y a le cas ou l'element rencontre est un murHorizontal
}

void joueurEclair(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv)
{
    if (grille.zoneJeu[iLigne][iColonne + 1].representation == ' ')
    {
        grille.zoneJeu[iLigne][iColonne + 1] = {'>', cyan, true};
    }
    else if (grille.zoneJeu[iLigne][iColonne + 1].representation == 'N')
    {
        grille.zoneJeu[iLigne][iColonne + 1] = {'X', rouge, false};
        adversairesViv--;
    }
    else //if (grille.zoneJeu[iLigne][iColonne + 1].representation == '<') le else n'est vrai que dans le cas ou l'element suivant est une flamme 
    {
        grille.zoneJeu[iLigne][iColonne + 1] = {'X', rouge, false};
    }
}