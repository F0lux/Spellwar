/**
 * @file creerZoneJeu.cpp
 * @author Rafael Masson - Arthur Baros
 * @brief Partie du corps du module spellwar.h
 * @date 2023-12-02
 */
#include "spellwar.h"

//****************************************************************************
// DECLARATION DES SOUS-PROGRAMMES
//****************************************************************************
/**
 * @brief Permet de tester s'il faut affecter a l'element se trouvant en indiceLigne l'enregistrement murHorizontal
 *
 * @param [in] indiceLigne l'indice de la ligne courante de la grille.
 * @param [in] element l'element a remplir.
 */
void remplirMurHorizontal(unsigned int indiceLigne, ElementDeJeu& element);

/**
 * @brief Permet de tester s'il faut affecter a l'element se trouvant en indiceLigne et indiceColonne l'enregistrement murVertical
 *
 * @param [in] indiceLigne l'indice de la ligne courante de la grille.
 * @param [in] indiceColonne l'indice de la colonne courante de la grille.
 * @param [in] element l'element a remplir.
 */
void remplirMurVertical(unsigned int indiceLigne, unsigned int indiceColonne, ElementDeJeu& element);

/**
 * @brief Permet de tester s'il faut affecter a l'element se trouvant en indiceLigne et indiceColonne l'enregistrement espaceVide
 *
 * @param [in] indiceLigne l'indice de la ligne courante de la grille.
 * @param [in] indiceColonne l'indice de la colonne courante de la grille.
 * @param [in] element l'element a remplir.
 */
void remplirEspaceVide(unsigned int indiceLigne, unsigned int indiceColonne, ElementDeJeu& element);

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
void creerZoneJeu(Spellwar &grille)
{
    // Variables locales
    ElementDeJeu elem;

    // Code de la procedure
    for (unsigned int indiceLigne = 0; indiceLigne < TAILLE_COLONNES; indiceLigne++)
    {
        for (unsigned int indiceColonne = 0; indiceColonne < TAILLE_LIGNES; indiceColonne++)
        {
            if (indiceLigne == 0 || indiceLigne == (TAILLE_COLONNES - 1))
            {
                elem = {'#', blanc, false};
            }
            else if (indiceLigne != 0 && indiceLigne != (TAILLE_COLONNES-1) && indiceColonne == 0)
            {
                elem = {'|', cyan, false};
            }
            else
            {
                elem = {' ', blanc, false};
            }
            grille.zoneJeu[indiceLigne][indiceColonne] = elem;
        }
    }
}

void remplirMurHorizontal(unsigned int indiceLigne, ElementDeJeu& element)
{
    if (indiceLigne == 0 || indiceLigne == (TAILLE_COLONNES - 1))
    {
        element = {'#', blanc, false};
    }
}

void remplirMurVertical(unsigned int indiceLigne, unsigned int indiceColonne, ElementDeJeu& element)
{
    if (indiceLigne != 0 && indiceLigne != (TAILLE_COLONNES-1) && indiceColonne == 0)
    {
        element = {'|', cyan, false};
    }
}

void remplirEspaceVide(unsigned int indiceLigne, unsigned int indiceColonne, ElementDeJeu& element)
{
    if (indiceLigne != 0 && indiceLigne != TAILLE_COLONNES && indiceColonne != 0)
    {
        element = {' ', blanc, false};
    }
}