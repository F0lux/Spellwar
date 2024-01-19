/*
 Programme : positionnerPersonnages.cpp
 But : Partie du corps du module spellwar.h
 Auteurs : Rafael Masson - Arthur Baros
 Date de derniere modification : 18/01/2024
*/
#include "spellwar.h"

//****************************************************************************
// DECLARATION DES SOUS-PROGRAMMES
//****************************************************************************

/* Permet de positionner les arcaflammes et les necrogriffes aleatoirement
 * Prend en parametre la grille de jeu a modifier,
 * nbArca le nombre d'arcaflamme a positionner et nbNecro le nombre de necrogriffe a positionner*/
void positionnerArcaNecro(Spellwar &grille, unsigned int nbArca, unsigned int nbNecro);

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************

void positionnerPersonnages(Spellwar &grille)
{
    // Variables
    unsigned int nbArcaflamme;
    unsigned int nbNecrogriffe;

    // Code de la procedure
    // Positionner le joueur
    grille.zoneJeu[TAILLE_COLONNES / 2][1] = creerJoueur();

    // Positionner les adversaires
    // Nombre d'arcaflammes/necrogriffes a afficher
    nbArcaflamme = random(0, NOMBRES_ADVERSAIRES);
    nbNecrogriffe = NOMBRES_ADVERSAIRES - nbArcaflamme;

    // Positionner le(s) arcaflamme(s) et le(s) necrogriffe(s)
    positionnerArcaNecro(grille, nbArcaflamme, nbNecrogriffe);
}

void positionnerArcaNecro(Spellwar &grille, unsigned int nbArca, unsigned int nbNecro)
{
    // Variables
    unsigned int indiceLigne;

    // Code de la procedure
    for (unsigned int i = 0; i < nbArca; i++)
    {
        indiceLigne = random(1, (TAILLE_COLONNES - 2));
        if (grille.zoneJeu[indiceLigne][TAILLE_LIGNES - 1].entite == espaceVide)
        {
            grille.zoneJeu[indiceLigne][TAILLE_LIGNES - 1] = creerArcaflamme();
        }
        else
        {
            // on annule l'avancee dans la boucle si on a pas reussi a positionner l'arcaflamme
            i--;
        }
    }
    for (unsigned int j = 0; j < nbNecro; j++)
    {
        indiceLigne = random(1, (TAILLE_COLONNES - 2));
        if (grille.zoneJeu[indiceLigne][TAILLE_LIGNES - 1].entite == espaceVide)
        {
            grille.zoneJeu[indiceLigne][TAILLE_LIGNES - 1] = creerNecrogriffe();
        }
        else
        {
            // on annule l'avancee dans la boucle si on a pas reussi a positionner le necrogriffe
            j--;
        }
    }
}