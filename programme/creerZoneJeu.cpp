/**
 * @file creerZoneJeu.cpp
 * @author Rafael Masson - Arthur Baros
 * @brief Partie du corps du module spellwar.h
 * @date 2023-12-08
 */
#include "spellwar.h"

//****************************************************************************
// DECLARATION DES SOUS-PROGRAMMES
//****************************************************************************
/**
 * @brief Retourne l'element a affecter a la case courante
 *
 * @param [in] iLigne l'indice de la ligne courante de la grille.
 * @param [in] iColonne l'indice de la colonne courante de la grille.
 */
ElementDeJeu remplirMursEspacesVide(unsigned int iLigne, unsigned int iColonne);

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
void creerZoneJeu(Spellwar &grille)
{
    // Variables locales
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
    // Variables locales
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