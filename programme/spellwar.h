/**
 * @file spellwar.h
 * @author Rafael Masson - Arthur Baros
 * @brief Fichier d'entête du module spellwar
 * @date 2023-12-02
 */
#ifndef SPELLWAR_H
#define SPELLWAR_H

#include "game-tools.h"

const unsigned int TAILLE_LIGNES = 35;  // Largeur de la zone de jeu
const unsigned int TAILLE_COLONNES = 8; // Hauteur de la zone de jeu

/**
 * @brief Enregistrement caracterisant les differents
 * elements de jeu utilises par le jeu spellwar
 *
 * @example Enregistrements possibles de ElementDeJeu
 * @example ElementDeJeu espaceVide = {' ', blanc, false};
 * @example ElementDeJeu murVertical = {'|', cyan, true};
 * @example ElementDeJeu murHorizontal = {'#', blanc, false};
 * @example ElementDeJeu joueur = {'J', cyan, false};
 * @example ElementDeJeu eclair = {'>', cyan, true};
 * @example ElementDeJeu arcaflamme = {'A', jaune, false};
 * @example ElementDeJeu flamme = {'<', jaune, true};
 * @example ElementDeJeu necrogriffe = {'N', violet, false};
 * 
 */
struct ElementDeJeu
{
    char representation;
    Couleur couleur;
    bool deplaceCeTour = false;
};

enum SituationFinJeu
{
    abandon,
    mortJoueur,
    mortAdversaires
};

struct Spellwar
{
    ElementDeJeu zoneJeu[TAILLE_LIGNES][TAILLE_COLONNES];
};

/**
 * @brief Permet de creer la zone de jeu dans une grille de jeu de spellwar
 *
 * @param [in] grille la grille de jeu a remplir avec les elements de spellwar
 */
void creerZoneJeu(Spellwar& grille);

/**
 * @brief Permet d'afficher sur le terminal la grille de jeu de spellwar
 *
 * @param [in] grille la grille de jeu a afficher
 */
void afficherZoneJeu(Spellwar grille);

#endif // SPELLWAR_H