/*
 Programme : spellwar.h
 But : Fichier d'entête du module spellwar
 Auteurs : Rafael Masson - Arthur Baros
 Date de derniere modification : 18/01/2024
*/
#ifndef SPELLWAR_H
#define SPELLWAR_H

#include "game-tools.h"

const unsigned int TAILLE_LIGNES = 35;      // Largeur de la zone de jeu
const unsigned int TAILLE_COLONNES = 8;     // Hauteur de la zone de jeu
const unsigned int NOMBRES_ADVERSAIRES = 3; // Nombre initial d'adversaires

// Type enumere listant les entites existantes dans spellwar
enum Entite
{
    joueur,
    arcaflamme,
    necrogriffe,
    eclair,
    flamme,
    murVertical,
    murHorizontal,
    espaceVide,
    marqueurCollision
};

// Enregistrement caracterisant les differents elements de jeu utilises par le jeu spellwar
struct ElementDeJeu
{
    Entite entite;
    char representation;
    Couleur couleur;
    bool deplaceCeTour = false;
};

// Type enumere listant les differentes fins de partie possibles dans spellwar
enum SituationFinJeu
{
    abandon,
    mortJoueur,
    victoireJoueur
};

// Enregistrement caracterisant la grille de jeu composes d'ElementDeJeu(s) et de la SituationFinJeu utilises par le jeu spellwar
struct Spellwar
{
    ElementDeJeu zoneJeu[TAILLE_COLONNES][TAILLE_LIGNES];
    SituationFinJeu finJeu;
};

// Procedure permettant de creer la zone de jeu dans une grille de jeu de spellwar
void creerZoneJeu(Spellwar &grille);

/* Fonction qui retourne un enregistrement de joueur, prend en parametre deplCeTour qui si vrai, 
la valeur de deplaceCeTour de joueur sera vrai ; ce parametre vaut faux par defaut */
ElementDeJeu creerJoueur(bool deplCeTour = false);

/* Fonction qui retourne un enregistrement d'arcaflamme, prend en parametre deplCeTour qui si vrai, 
la valeur de deplaceCeTour de l'arcaflamme sera vrai ; ce parametre vaut faux par defaut */
ElementDeJeu creerArcaflamme(bool deplCeTour = false);

/* Fonction qui retourne un enregistrement de necrogriffe, prend en parametre deplCeTour qui si vrai, 
la valeur de deplaceCeTour de necrogriffe sera vrai ; ce parametre vaut faux par defaut */
ElementDeJeu creerNecrogriffe(bool deplCeTour = false);

/* Fonction qui retourne un enregistrement d'eclair, prend en parametre deplCeTour qui si vrai, 
la valeur de deplaceCeTour de l'eclair sera vrai ; ce parametre vaut faux par defaut */
ElementDeJeu creerEclair(bool deplCeTour = false);

/* Fonction qui retourne un enregistrement de flamme, prend en parametre deplCeTour qui si vrai, 
la valeur de deplaceCeTour de flamme sera vrai ; ce parametre vaut faux par defaut */
ElementDeJeu creerFlamme(bool deplCeTour = false);

// Fonction qui retourne un enregistrement de murVertical
ElementDeJeu creerMurVertical();

// Fonction qui retourne un enregistrement de murHorizontal
ElementDeJeu creerMurHorizontal();

// Fonction qui retourne un enregistrement d'espaceVide
ElementDeJeu creerEspaceVide();

// Fonction qui retourne un enregistrement de marqueurCollision
ElementDeJeu creerMarqueurCollision();

// Fonction qui retourne la raison de la fin de la partie de la zone de jeu grille
SituationFinJeu obtenirFinJeu(const Spellwar &grille);

// Procedure qui definit la fin de la partie de grille a finJ
void definirFinJeu(Spellwar &grille, const SituationFinJeu &finJ);

// Procedure qui definit l'element en iLigne iColonne de la zone de jeu grille a element 
void definirElement(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, ElementDeJeu element);

/* Procedure qui permet de jouer un tour de spellwar dans la zone de jeu grille 
et qui prend en parametre l'action courante du joueur actionJ et le nombre d'aversaires encore en vie adversairesViv */
void jouerUnTour(Spellwar &grille, char actionJ, unsigned int &adversairesViv);

/* Procedure qui permet de positionner le joueur et les adversaires du jeu spellwar 
Prend en paramtre grille la grille de jeu a modifier */
void positionnerPersonnages(Spellwar &grille);

// Procedure qui permet d'afficher la zone de jeu grille et les actions possibles pour le joueur
void afficherPlateauEtInformations(const Spellwar &grille);

/**
 * @brief Permet de supprimer les marques de collision du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 */
void supprimerMarqueCollision(Spellwar &grille);

/**
 * @brief Permet d'executer l'action saisie pour le joueur du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] actionJ l'action du joueur
 * @param [in] iLigne l'indice de la ligne de l'element
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'aversaires encore en vie
 */
void jouerJoueur(Spellwar &grille, char actionJ, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/**
 * @brief Permet de faire jouer un arcaflamme du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] iLigne l'indice de la ligne de l'element
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void jouerArcaflamme(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/**
 * @brief Permet de faire jouer un necrogriffe du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] actionJ l'action du joueur
 * @param [in] iLigne l'indice de la ligne de l'element
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void jouerNecrogriffe(Spellwar &grille, char actionJ, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/**
 * @brief Permet de deplacer un eclair du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] iLigne l'indice de la ligne de l'element
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void deplacerEclair(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/**
 * @brief Permet de deplacer une flamme du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 * @param [in] iLigne l'indice de la ligne de l'element
 * @param [in] iColonne l'indice de la colonne de l'element
 * @param [in] adversairesViv nombre d'adversaires encore en vie
 */
void deplacerFlamme(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/**
 * @brief Permet de mettre a faux deplaceCeTour pour tout les elements du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 */
void reinitialiserDeplacements(Spellwar &grille);

bool estJoueurPasDeplCeTour(Spellwar &grille, unsigned int iLigne, unsigned int iColonne);

bool estArcaflammePasDeplCeTour(Spellwar &grille, unsigned int iLigne, unsigned int iColonne);

bool estNecrogriffePasDeplCeTour(Spellwar &grille, unsigned int iLigne, unsigned int iColonne);

bool estEclairPasDeplCeTour(Spellwar &grille, unsigned int iLigne, unsigned int iColonne);

bool estFlammePasDeplCeTour(Spellwar &grille, unsigned int iLigne, unsigned int iColonne);

bool estSurPremiereColonne(unsigned int iColonne);

bool estSurDerniereColonne(unsigned int iColonne);

bool estSurPremiereOuDerniereLigne(unsigned int iLigne);

bool estSurPremiereColonnePasPremiereLignePasDerniereLigne(unsigned int iLigne, unsigned int iColonne);

/**
 * @brief Permet d'afficher un message expliquant la raison de la fin de la partie du jeu spellwar
 *
 * @param [in] grille la grille de jeu qui contient la raison de la fin de la partie
 */
void finirLaPartie(const Spellwar &grille);

#endif // SPELLWAR_H