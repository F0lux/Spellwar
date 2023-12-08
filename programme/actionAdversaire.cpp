/**
 * @file actionAdversaire.cpp
 * @author Rafael Masson - Arthur Baros
 * @brief Partie du corps du module spellwar.h
 * @date 2023-12-07
 */
#include "spellwar.h"
//#include <iostream>
//****************************************************************************
// DECLARATION DES SOUS-PROGRAMMES
//****************************************************************************
/**
 * @brief Permet de faire monter un arcaflamme du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] iLigne l'indice de la ligne de l'element 
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void arcaflammeMonter(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv);

/**
 * @brief Permet de faire descendre un arcaflamme du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] iLigne l'indice de la ligne de l'element 
 * @param [in] iColonne l'indice de la colonne de l'element
 */
void arcaflammeDescendre(Spellwar &grille, unsigned int iLigne, unsigned int iColonne);

/**
 * @brief Permet de faire tirer un flamme a un arcaflamme du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] iLigne l'indice de la ligne de l'element 
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void arcaflammeFlamme(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv);

/**
 * @brief Permet de faire se deplacer en diagonale haut-gauche un necrogriffe du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] actionJ l'action du joueur
 * @param [in] iLigne l'indice de la ligne de l'element 
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void necrogriffeDiagHaut(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv);

/**
 * @brief Permet de faire aller a gauche un necrogriffe du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] iLigne l'indice de la ligne de l'element 
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void necrogriffeGauche(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv);

/**
 * @brief Permet de faire se deplacer en diagonale bas-gauche un necrogriffe du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] actionJ l'action du joueur
 * @param [in] iLigne l'indice de la ligne de l'element 
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void necrogriffeDiagBas(Spellwar &grille, char actionJ, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv);

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
void actionArcaflamme(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv)
{
    // Variables
    enum actArca
    {
        monter = 0,
        descendre = 1,
        flamme = 2
    };

    unsigned int borneMinAct = 0;
    unsigned int borneMaxAct = 2;
    int numAct;
    actArca action;

    // Code procedure
    numAct = random(borneMinAct, borneMaxAct);
    switch (numAct)
    {
    case 0:
        action = monter;
        break;
    case 1:
        action = descendre;
        break;
    case 2:
        action = flamme;
        break;
    default:
        break;
    }

    switch (action)
    {
    case monter:
        arcaflammeMonter(grille, iLigne, iColonne, adversairesViv);
        break;
    case descendre:
        arcaflammeDescendre(grille, iLigne, iColonne);
        break;
    case flamme:
        arcaflammeFlamme(grille, iLigne, iColonne, adversairesViv);
        break;
    default:
        break;
    }
}

void arcaflammeMonter(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv)
{
    if (grille.zoneJeu[iLigne - 1][iColonne].representation == ' ')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne - 1][iColonne] = {'A', rouge, true};
    }
    else if (grille.zoneJeu[iLigne - 1][iColonne].representation == '>')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne - 1][iColonne] = {'X', rouge, false};
        adversairesViv--;
    }
    // pas de else pour l'eclair car il y a les cas ou l'element rencontre est un murHorizontal, un arcaflamme, ou un necrogriffe
}

void arcaflammeDescendre(Spellwar &grille, unsigned int iLigne, unsigned int iColonne)
{
    if (grille.zoneJeu[iLigne + 1][iColonne].representation == ' ')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne + 1][iColonne] = {'A', rouge, true};
    }
    /*else if (grille.zoneJeu[iLigne - 1][iColonne].representation == '>')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne + 1][iColonne] = {'X', rouge, false};
        adversairesViv--;
    } pas besoin car a ce tour, l'eclair avance dcp il se le prend pas, par contre faut regarder dans le deplacement de l'eclair si on tue l'arca*/
    // pas de else pour l'eclair car il y a les cas ou l'element rencontre est un murHorizontal, un arcaflamme, ou un necrogriffe
}

void arcaflammeFlamme(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv)
{
    if (grille.zoneJeu[iLigne][iColonne - 1].representation == ' ')
    {
        grille.zoneJeu[iLigne][iColonne - 1] = {'<', rouge, true};
    }
    else if (grille.zoneJeu[iLigne][iColonne - 1].representation == 'N')
    {
        grille.zoneJeu[iLigne][iColonne - 1] = {'X', rouge, false};
        adversairesViv--;
    }
    else // if (grille.zoneJeu[iLigne][iColonne + 1].representation == '>') le else n'est vrai que dans le cas ou l'element suivant est un eclair
    {
        grille.zoneJeu[iLigne][iColonne - 1] = {'X', rouge, false};
    }
}







void actionNecrogriffe(Spellwar &grille, char actionJ, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv)
{
    // Variables
    enum actNecr
    {
        diagHaut = 0,
        gauche = 1,
        diagBas = 2
    };

    unsigned int borneMinAct = 0;
    unsigned int borneMaxAct = 2;
    int numAct;
    actNecr action;

    // Code procedure
    numAct = random(borneMinAct, borneMaxAct);
    switch (numAct)
    {
    case 0:
        action = diagHaut;
        break;
    case 1:
        action = gauche;
        break;
    case 2:
        action = diagBas;
        break;
    default:
        break;
    }

    switch (action)
    {
    case diagHaut:
        necrogriffeDiagHaut(grille, iLigne, iColonne, adversairesViv);
        break;
    case gauche:
        necrogriffeGauche(grille, iLigne, iColonne, adversairesViv);
        break;
    case diagBas:
        necrogriffeDiagBas(grille, actionJ, iLigne, iColonne, adversairesViv);
        break;
    default:
        break;
    }
}

void necrogriffeDiagHaut(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv)
{
    if (grille.zoneJeu[iLigne - 1][iColonne - 1].representation == ' ')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne - 1][iColonne - 1] = {'N', violet, true};
    }
    else if (grille.zoneJeu[iLigne - 1][iColonne - 1].representation == '>' || grille.zoneJeu[iLigne - 1][iColonne - 1].representation == '<' ||
    grille.zoneJeu[iLigne - 1][iColonne - 1].representation == '|')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne - 1][iColonne - 1] = {'X', rouge, false};
        adversairesViv--;
    }
    else if (grille.zoneJeu[iLigne - 1][iColonne - 1].representation == 'J')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne - 1][iColonne - 1] = {'N', violet, true};
        grille.finJeu = mortJoueur;
    }
    // pas de else pour le joueur car il y a les cas ou l'element rencontre est un murHorizontal, ou un necrogriffe
}

void necrogriffeGauche(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv)
{
    if (grille.zoneJeu[iLigne][iColonne - 1].representation == ' ')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne][iColonne - 1] = {'N', violet, true};
    }
    else if (grille.zoneJeu[iLigne][iColonne - 1].representation == '>' || grille.zoneJeu[iLigne][iColonne - 1].representation == '<' ||
    grille.zoneJeu[iLigne][iColonne - 1].representation == '|')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne][iColonne - 1] = {'X', rouge, false};
        adversairesViv--;
    }
    else if (grille.zoneJeu[iLigne][iColonne - 1].representation == 'J')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne][iColonne - 1] = {'N', violet, true};
        grille.finJeu = mortJoueur;
    }
    // pas de else pour le joueur car il y a le cas ou l'element rencontre est un necrogriffe
}

void necrogriffeDiagBas(Spellwar &grille, char actionJ, unsigned int iLigne, unsigned int iColonne, unsigned int adversairesViv)
{
    if (grille.zoneJeu[iLigne + 1][iColonne - 1].representation == ' ')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne + 1][iColonne - 1] = {'N', violet, true};
    }
    else if (grille.zoneJeu[iLigne + 1][iColonne - 1].representation == '|')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne + 1][iColonne - 1] = {'X', rouge, false};
        adversairesViv--;
    }
    else if (grille.zoneJeu[iLigne + 1][iColonne - 1].representation == '>')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne + 1][iColonne - 1] = {'N', violet, false};
        grille.zoneJeu[iLigne + 1][iColonne] = {'>', cyan, true};
    }
    else if (grille.zoneJeu[iLigne + 1][iColonne - 1].representation == '<')
    {
        grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
        grille.zoneJeu[iLigne + 1][iColonne - 1] = {'N', violet, false};
        grille.zoneJeu[iLigne + 1][iColonne - 2] = {'<', rouge, true};
    }
    else if (grille.zoneJeu[iLigne + 1][iColonne - 1].representation == 'J')
    {
        if (grille.zoneJeu[iLigne + 1][iColonne - 1].deplaceCeTour == true)
        {
            grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
            grille.zoneJeu[iLigne + 1][iColonne - 1] = {'N', violet, true};
            grille.finJeu = mortJoueur;
        }
        else
        {
            actionJoueur(grille, actionJ, iLigne+1, iColonne-1, adversairesViv);
            if (grille.zoneJeu[iLigne + 1][iColonne - 1].representation == 'J')
            {
                grille.finJeu = mortJoueur;
            }
            grille.zoneJeu[iLigne][iColonne] = {' ', blanc, false};
            grille.zoneJeu[iLigne + 1][iColonne - 1] = {'N', violet, true};
        }
    }
    // pas de else pour le joueur car il y a les cas ou l'element rencontre est un murHorizontal, ou un necrogriffe
}