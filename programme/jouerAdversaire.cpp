/*
 Programme : jouerAdversaire.cpp
 But : Partie du corps du module spellwar.h
 Auteurs : Rafael Masson - Arthur Baros
 Date de derniere modification : 18/01/2024
*/
#include "spellwar.h"

//****************************************************************************
// DECLARATION DES SOUS-PROGRAMMES
//****************************************************************************

/* BUT : Permet de faire monter d'une ligne un arcaflamme du jeu spellwar
 * Prend en parametre la grille de jeu a modifier, iLigne l'indice de la ligne de l'element,
 * iColonne l'indice de la colonne de l'element et adversairesViv le nombre d'adversaires encore en vie */
void arcaflammeMonter(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/* BUT : Permet de faire descendre d'une ligne un arcaflamme du jeu spellwar
 * Prend en parametre la grille de jeu a modifier, iLigne l'indice de la ligne de l'element,
 * iColonne l'indice de la colonne de l'element et adversairesViv le nombre d'adversaires encore en vie */
void arcaflammeDescendre(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/* BUT : Permet de faire tirer un flamme a un arcaflamme du jeu spellwar
 * Prend en parametre la grille de jeu a modifier, iLigne l'indice de la ligne de l'element,
 * iColonne l'indice de la colonne de l'element et adversairesViv le nombre d'adversaires encore en vie */
void arcaflammeFlamme(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/* BUT : Permet de faire se deplacer en diagonale haut-gauche un necrogriffe du jeu spellwar
 * Prend en parametre la grille de jeu a modifier, iLigne l'indice de la ligne de l'element,
 * iColonne l'indice de la colonne de l'element et adversairesViv le nombre d'adversaires encore en vie */
void necrogriffeDiagHaut(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/* BUT : Permet de faire aller a gauche un necrogriffe du jeu spellwar
 * Prend en parametre la grille de jeu a modifier, iLigne l'indice de la ligne de l'element,
 * iColonne l'indice de la colonne de l'element et adversairesViv le nombre d'adversaires encore en vie */
void necrogriffeGauche(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/* BUT : Permet de faire se deplacer en diagonale bas-gauche un necrogriffe du jeu spellwar
 * Prend en parametre la grille de jeu a modifier, actionJ l'action du joueur, iLigne l'indice de la ligne de l'element,
 * iColonne l'indice de la colonne de l'element et adversairesViv le nombre d'adversaires encore en vie */
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

    // Code de la procedure
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
    // Variables
    ElementDeJeu elementSuivant;

    // Code de la procedure
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
    // Variables
    ElementDeJeu elementSuivant;

    // Code de la procedure
    elementSuivant = grille.zoneJeu[iLigne + 1][iColonne];

    if (elementSuivant.entite == espaceVide || elementSuivant.entite == eclair)
    {
        if (elementSuivant.entite == eclair)
        {
            /* comme l'eclair est en dessous, il n'a pas encore ete deplace, pour faire apparaitre descendre
            l'arcaflamme a cette position on doit d'abord deplacer l'eclair */
            deplacerEclair(grille, iLigne + 1, iColonne, adversairesViv);
        }

        definirElement(grille, iLigne, iColonne, creerEspaceVide());
        definirElement(grille, iLigne + 1, iColonne, creerArcaflamme(true));
    }
    else if (elementSuivant.entite == arcaflamme)
    {
        /* comme l'arcaflamme est en dessous, il n'a pas encore ete deplace, pour faire apparaitre descendre
        l'arcaflamme a cette position on doit d'abord deplacer celui qui s'y trouve deja */
        jouerArcaflamme(grille, iLigne + 1, iColonne, adversairesViv);

        // s'il n'est plus en dessous, alors on peut descendre l'arcaflamme
        if (elementSuivant.entite != arcaflamme)
        {
            definirElement(grille, iLigne, iColonne, creerEspaceVide());
            definirElement(grille, iLigne + 1, iColonne, creerArcaflamme(true));
        }
    }
}

void arcaflammeFlamme(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv)
{
    // Variables
    ElementDeJeu elementSuivant;

    // Code de la procedure
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

    // Code de la procedure
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
    // Variables
    ElementDeJeu elementSuivant;

    // Code de la procedure
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
    // Variables
    ElementDeJeu elementSuivant;

    // Code de la procedure
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
    // Variables
    ElementDeJeu elementSuivant;

    // Code de la procedure
    elementSuivant = grille.zoneJeu[iLigne + 1][iColonne - 1];

    if (elementSuivant.entite == espaceVide || elementSuivant.entite == eclair || elementSuivant.entite == flamme)
    {
        if (elementSuivant.entite == eclair)
        {
            /* comme l'eclair est en dessous, il n'a pas encore ete deplace, pour faire apparaitre descendre
            le necrogriffe a cette position on doit d'abord deplace celui qui s'y trouve deja */
            deplacerEclair(grille, iLigne + 1, iColonne - 1, adversairesViv);
        }
        else if (elementSuivant.entite == flamme)
        {
            /* comme la flamme est en dessous, il n'a pas encore ete deplace, pour faire apparaitre descendre
            le necrogriffe a cette position on doit d'abord deplace celui qui s'y trouve deja */
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
        // Pour le joueur specifiquement, il est possible qu'il se trouve en bas a gauche du necrogriffe en ayant deja joue/pas encore joue
        if (elementSuivant.deplaceCeTour)
        {
            definirElement(grille, iLigne, iColonne, creerEspaceVide());
            definirElement(grille, iLigne + 1, iColonne - 1, creerNecrogriffe(true));
            definirFinJeu(grille, mortJoueur);
        }
        else
        {
            // on fait jouer le joueur a cette position
            jouerJoueur(grille, actionJ, iLigne + 1, iColonne - 1, adversairesViv);

            // s'il est encore en bas a gauche
            if (elementSuivant.entite == joueur)
            {
                // le necrogriffe se deplace pour tuer le joueur
                definirFinJeu(grille, mortJoueur);
            }
            definirElement(grille, iLigne, iColonne, creerEspaceVide());
            definirElement(grille, iLigne + 1, iColonne - 1, creerNecrogriffe(true));
        }
    }
}