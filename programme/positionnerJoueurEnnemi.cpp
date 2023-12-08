/**
 * @file creerJoueurEnnemi.cpp
 * @author Rafael Masson - Arthur Baros
 * @brief Partie du corps du module spellwar.h
 * @date 2023-12-07
 */
#include "spellwar.h"

//****************************************************************************
// DECLARATION DES SOUS-PROGRAMMES
//****************************************************************************
/**
 * @brief Permet de positionner les arcaflammes et les necrogriffes
 *
 * @param [in] nbArca le nombre d'arcaflamme a positionner
 * @param [in] nbNecro le nombre de necrogriffe a positionner
 * @param [in] grille la grille de jeu a modifier
 */
void positionnerArcaNecro(Spellwar& grille, unsigned int nbArca, unsigned int nbNecro);

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
void positionnerJoueurEnnemi(Spellwar& grille)
{
    // Variables
    unsigned int nbArcaflamme;
    unsigned int nbNecrogriffe;

    // Code procedure
    // Positionner le joueur
    grille.zoneJeu[TAILLE_COLONNES / 2][1] = {'J', cyan, false};

    // Positionner les adversaires
    // Nombre d'arcaflammes/necrogriffes a afficher
    nbArcaflamme = random(0,NOMBRES_ADVERSAIRES);
    nbNecrogriffe = NOMBRES_ADVERSAIRES - nbArcaflamme;

    // Positionner le(s) arcaflamme(s) et le(s) necrogriffe(s)
    positionnerArcaNecro(grille, nbArcaflamme, nbNecrogriffe);
}

void positionnerArcaNecro(Spellwar& grille, unsigned int nbArca, unsigned int nbNecro)
{
    // Variables
    unsigned int indiceLigne;

    // Code procédure
    for (unsigned int i = 0; i < nbArca; i++)
    {
        indiceLigne = random(1, (TAILLE_COLONNES-2));
        if (grille.zoneJeu[indiceLigne][TAILLE_LIGNES-1].representation == ' ')
        {
            grille.zoneJeu[indiceLigne][TAILLE_LIGNES-1] = {'A', rouge, false};
        }
        else
        {
            i--;
        }
    } 
    for (unsigned int j = 0; j < nbNecro; j++)
    {
        indiceLigne = random(1, (TAILLE_COLONNES-2));
        if (grille.zoneJeu[indiceLigne][TAILLE_LIGNES-1].representation == ' ')
        {
            grille.zoneJeu[indiceLigne][TAILLE_LIGNES-1] = {'N', violet, false};
        }
        else
        {
            j--;
        }
    }   
}