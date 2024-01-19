/*
 Programme : creerZoneJeu.cpp
 But : Partie du corps du module spellwar.h
 Auteurs : Rafael Masson - Arthur Baros
 Date de derniere modification : 18/01/2024
*/
#include "spellwar.h"

//****************************************************************************
// DECLARATION DES SOUS-PROGRAMMES
//****************************************************************************

/* Retourne l'element (murHorizontal, murVertical ou espaceVide) a affecter a la case courante en 
iLigne l'indice de la ligne courante et iColonne l'indice de la colonne courante de la grille. */
ElementDeJeu remplirMursEspacesVide(unsigned int iLigne, unsigned int iColonne);


//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
void creerZoneJeu(Spellwar &grille)
{
    // Variables
    ElementDeJeu element;

    // Code de la procedure
    for (unsigned int indiceLigne = 0; indiceLigne < TAILLE_COLONNES; indiceLigne++)
    {
        for (unsigned int indiceColonne = 0; indiceColonne < TAILLE_LIGNES; indiceColonne++)
        {
            element = remplirMursEspacesVide(indiceLigne, indiceColonne);
            grille.zoneJeu[indiceLigne][indiceColonne] = element;
        }
    }
}

ElementDeJeu remplirMursEspacesVide(unsigned int iLigne, unsigned int iColonne)
{
    // Variables
    ElementDeJeu elem;

    // Code de la fonction
    if (estSurPremiereOuDerniereLigne(iLigne))
    {
        elem = creerMurHorizontal();
    }
    else if (estSurPremiereColonnePasPremiereLignePasDerniereLigne(iLigne, iColonne))
    {
        elem = creerMurVertical();
    }
    else
    {
        elem = creerEspaceVide();
    }
    return elem;
}