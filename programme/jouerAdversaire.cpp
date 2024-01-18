/**
 * @file actionAdversaire.cpp
 * @author Rafael Masson - Arthur Baros
 * @brief Partie du corps du module spellwar.h
 * @date 2023-12-07
 */
#include "spellwar.h"

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
void arcaflammeMonter(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/**
 * @brief Permet de faire descendre un arcaflamme du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] iLigne l'indice de la ligne de l'element
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void arcaflammeDescendre(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/**
 * @brief Permet de faire tirer un flamme a un arcaflamme du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] iLigne l'indice de la ligne de l'element
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void arcaflammeFlamme(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/**
 * @brief Permet de faire se deplacer en diagonale haut-gauche un necrogriffe du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] actionJ l'action du joueur
 * @param [in] iLigne l'indice de la ligne de l'element
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void necrogriffeDiagHaut(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/**
 * @brief Permet de faire aller a gauche un necrogriffe du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] iLigne l'indice de la ligne de l'element
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void necrogriffeGauche(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/**
 * @brief Permet de faire se deplacer en diagonale bas-gauche un necrogriffe du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] actionJ l'action du joueur
 * @param [in] iLigne l'indice de la ligne de l'element
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void necrogriffeDiagBas(Spellwar &grille, char actionJ, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
void jouerArcaflamme(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
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
        arcaflammeDescendre(grille, iLigne, iColonne, adversairesViv);
        break;
    case flamme:
        arcaflammeFlamme(grille, iLigne, iColonne, adversairesViv);
        break;
    default:
        break;
    }
}

void arcaflammeMonter(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
{
    ElementDeJeu elementSuivant;

    elementSuivant = grille.zoneJeu[iLigne - 1][iColonne];

    if (elementSuivant.entite == espaceVide)
    {
        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne - 1, iColonne, creerArcaflamme(true));
    }
    else if (elementSuivant.entite == eclair)
    {
        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne - 1, iColonne, creerMarqueurCollision());
        adversairesViv--;
    }
}

void arcaflammeDescendre(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
{
    ElementDeJeu elementSuivant;

    elementSuivant = grille.zoneJeu[iLigne + 1][iColonne];

    if (elementSuivant.entite == espaceVide || elementSuivant.entite == eclair)
    {
        if (elementSuivant.entite == eclair)
        {
            deplacerEclair(grille, iLigne + 1, iColonne, adversairesViv);
        }

        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne + 1, iColonne, creerArcaflamme(true));
    }
    else if (elementSuivant.entite == arcaflamme)
    {
        jouerArcaflamme(grille, iLigne + 1, iColonne, adversairesViv);
        if (elementSuivant.entite != arcaflamme)
        {
            definirElement(grille, iLigne, iColonne, creerEspaceVide());
            definirElement(grille, iLigne + 1, iColonne, creerArcaflamme(true));
        }
    }
}

void arcaflammeFlamme(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
{
    ElementDeJeu elementSuivant;

    elementSuivant = grille.zoneJeu[iLigne][iColonne - 1];

    if (elementSuivant.entite == espaceVide)
    {
        definirElement(grille, iLigne, iColonne - 1, creerFlamme(true));
    }
    else if (elementSuivant.entite == necrogriffe || elementSuivant.entite == eclair)
    {
        if (elementSuivant.entite == necrogriffe)
        {
            adversairesViv--;
        }

        definirElement(grille, iLigne, iColonne - 1, creerMarqueurCollision());
    }
}

void jouerNecrogriffe(Spellwar &grille, char actionJ, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
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

void necrogriffeDiagHaut(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
{
    ElementDeJeu elementSuivant;

    elementSuivant = grille.zoneJeu[iLigne - 1][iColonne - 1];

    if (elementSuivant.entite == espaceVide || elementSuivant.entite == joueur)
    {
        if (elementSuivant.entite == joueur)
        {
            definirFinJeu(grille, mortJoueur);
        }

        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne - 1, iColonne - 1, creerNecrogriffe(true));
    }
    else if (elementSuivant.entite == eclair || elementSuivant.entite == flamme || elementSuivant.entite == murVertical)
    {
        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne - 1, iColonne - 1, creerMarqueurCollision());
        adversairesViv--;
    }
}

void necrogriffeGauche(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
{
    ElementDeJeu elementSuivant;

    elementSuivant = grille.zoneJeu[iLigne][iColonne - 1];

    if (elementSuivant.entite == espaceVide || elementSuivant.entite == joueur)
    {
        if (elementSuivant.entite == joueur)
        {
            definirFinJeu(grille, mortJoueur);
        }

        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne, iColonne - 1, creerNecrogriffe(true));
    }
    else if (elementSuivant.entite == eclair || elementSuivant.entite == flamme || elementSuivant.entite == murVertical)
    {
        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne, iColonne - 1, creerMarqueurCollision());
        adversairesViv--;
    }
}

void necrogriffeDiagBas(Spellwar &grille, char actionJ, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
{
    ElementDeJeu elementSuivant;

    elementSuivant = grille.zoneJeu[iLigne + 1][iColonne - 1];

    if (elementSuivant.entite == espaceVide || elementSuivant.entite == eclair || elementSuivant.entite == flamme)
    {
        if (elementSuivant.entite == eclair)
        {
            deplacerEclair(grille, iLigne + 1, iColonne - 1, adversairesViv);
        }
        else if (elementSuivant.entite == flamme)
        {
            deplacerFlamme(grille, iLigne + 1, iColonne - 1, adversairesViv);
        }

        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne + 1, iColonne - 1, creerNecrogriffe(true));
    }
    else if (elementSuivant.entite == murVertical)
    {
        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne + 1, iColonne - 1, creerMarqueurCollision());
        adversairesViv--;
    }
    else if (elementSuivant.entite == joueur)
    {
        if (elementSuivant.deplaceCeTour)
        {
            definirElement(grille, iLigne, iColonne, creerEspaceVide());
            definirElement(grille, iLigne + 1, iColonne - 1, creerNecrogriffe(true));
            definirFinJeu(grille, mortJoueur);
        }
        else
        {
            jouerJoueur(grille, actionJ, iLigne + 1, iColonne - 1, adversairesViv);
            if (elementSuivant.entite == joueur)
            {
                definirFinJeu(grille, mortJoueur);
            }
            definirElement(grille, iLigne, iColonne, creerEspaceVide());
            definirElement(grille, iLigne + 1, iColonne - 1, creerNecrogriffe(true));
        }
    }
}