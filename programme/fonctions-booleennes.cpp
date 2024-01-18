/**
 * @file fonctions-booleennes.cpp
 * @author Rafael Masson - Arthur Baros
 * @brief Partie du corps du module spellwar.h
 * @date 2023-01-16
 */
#include "spellwar.h"

bool estJoueurPasDeplCeTour(Spellwar &grille, unsigned int iLigne, unsigned int iColonne)
{
    return grille.zoneJeu[iLigne][iColonne].entite == joueur && !grille.zoneJeu[iLigne][iColonne].deplaceCeTour;
}

bool estArcaflammePasDeplCeTour(Spellwar &grille, unsigned int iLigne, unsigned int iColonne)
{
    return grille.zoneJeu[iLigne][iColonne].entite == arcaflamme && !grille.zoneJeu[iLigne][iColonne].deplaceCeTour;
}

bool estNecrogriffePasDeplCeTour(Spellwar &grille, unsigned int iLigne, unsigned int iColonne)
{
    return grille.zoneJeu[iLigne][iColonne].entite == necrogriffe && !grille.zoneJeu[iLigne][iColonne].deplaceCeTour;
}

bool estEclairPasDeplCeTour(Spellwar &grille, unsigned int iLigne, unsigned int iColonne)
{
    return grille.zoneJeu[iLigne][iColonne].entite == eclair && !grille.zoneJeu[iLigne][iColonne].deplaceCeTour;
}

bool estFlammePasDeplCeTour(Spellwar &grille, unsigned int iLigne, unsigned int iColonne)
{
    return grille.zoneJeu[iLigne][iColonne].entite == flamme && !grille.zoneJeu[iLigne][iColonne].deplaceCeTour;
}

bool estSurDerniereColonne(unsigned int iColonne)
{
    return iColonne == TAILLE_LIGNES - 1;
}

bool estSurPremiereOuDerniereLigne(unsigned int iLigne)
{
    return iLigne == 0 || iLigne == (TAILLE_COLONNES - 1);
}

bool estSurPremiereColonnePasPremiereLignePasDerniereLigne(unsigned int iLigne, unsigned int iColonne)
{
    return iLigne != 0 && iLigne != (TAILLE_COLONNES - 1) && iColonne == 0;
}