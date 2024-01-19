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

// BUT : Procedure permettant de creer la zone de jeu dans une grille de jeu de spellwar
void creerZoneJeu(Spellwar &grille);

/* BUT : Fonction qui retourne un enregistrement de joueur, prend en parametre deplCeTour qui si vrai,
la valeur de deplaceCeTour de joueur sera vrai ; ce parametre vaut faux par defaut */
ElementDeJeu creerJoueur(bool deplCeTour = false);

/* BUT : Fonction qui retourne un enregistrement d'arcaflamme, prend en parametre deplCeTour qui si vrai,
la valeur de deplaceCeTour de l'arcaflamme sera vrai ; ce parametre vaut faux par defaut */
ElementDeJeu creerArcaflamme(bool deplCeTour = false);

/* BUT : Fonction qui retourne un enregistrement de necrogriffe, prend en parametre deplCeTour qui si vrai,
la valeur de deplaceCeTour de necrogriffe sera vrai ; ce parametre vaut faux par defaut */
ElementDeJeu creerNecrogriffe(bool deplCeTour = false);

/* BUT : Fonction qui retourne un enregistrement d'eclair, prend en parametre deplCeTour qui si vrai,
la valeur de deplaceCeTour de l'eclair sera vrai ; ce parametre vaut faux par defaut */
ElementDeJeu creerEclair(bool deplCeTour = false);

/* BUT : Fonction qui retourne un enregistrement de flamme, prend en parametre deplCeTour qui si vrai,
la valeur de deplaceCeTour de flamme sera vrai ; ce parametre vaut faux par defaut */
ElementDeJeu creerFlamme(bool deplCeTour = false);

// BUT : Fonction qui retourne un enregistrement de murVertical
ElementDeJeu creerMurVertical();

// BUT : Fonction qui retourne un enregistrement de murHorizontal
ElementDeJeu creerMurHorizontal();

// BUT : Fonction qui retourne un enregistrement d'espaceVide
ElementDeJeu creerEspaceVide();

// BUT : Fonction qui retourne un enregistrement de marqueurCollision
ElementDeJeu creerMarqueurCollision();

// BUT : Fonction qui retourne la raison de la fin de la partie de la zone de jeu grille
SituationFinJeu obtenirFinJeu(const Spellwar &grille);

// BUT : Procedure qui definit la fin de la partie de grille a finJ
void definirFinJeu(Spellwar &grille, const SituationFinJeu &finJ);

// BUT : Procedure qui definit l'element en iLigne iColonne de la zone de jeu grille a element
void definirElement(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, ElementDeJeu element);

/* BUT : Procedure qui permet de jouer un tour de spellwar dans la zone de jeu grille
et qui prend en parametre l'action courante du joueur actionJ et le nombre d'aversaires encore en vie adversairesViv */
void jouerUnTour(Spellwar &grille, char actionJ, unsigned int &adversairesViv);

/* BUT : Procedure qui permet de positionner le joueur et les adversaires du jeu spellwar
Prend en paramtre grille la grille de jeu a modifier */
void positionnerPersonnages(Spellwar &grille);

// BUT : Procedure qui permet d'afficher la zone de jeu grille et les actions possibles pour le joueur
void afficherPlateauEtInformations(const Spellwar &grille);

// BUT : Procedure qui permet de supprimer les marques de collision dans la zone de jeu grille
void supprimerMarqueCollision(Spellwar &grille);

/* BUT : Procedure qui permet d'executer l'action saisie pour le joueur du jeu spellwar
 * Prend en parametre la grille de jeu a modifier, actionJ l'action du joueur, iLigne l'indice de la ligne de l'element,
 * iColonne l'indice de la colonne de l'element et adversairesViv le nombre d'adversaires encore en vie */
void jouerJoueur(Spellwar &grille, char actionJ, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/* BUT : Procedure qui permet de faire jouer un arcaflamme du jeu spellwar
 * Prend en parametre la grille de jeu a modifier, iLigne l'indice de la ligne de l'element,
 * iColonne l'indice de la colonne de l'element et adversairesViv le nombre d'adversaires encore en vie */
void jouerArcaflamme(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/* BUT : Procedure qui permet de faire jouer un necrogriffe du jeu spellwar
 * Prend en parametre la grille de jeu a modifier, actionJ l'action du joueur, iLigne l'indice de la ligne de l'element,
 * iColonne l'indice de la colonne de l'element et adversairesViv le nombre d'adversaires encore en vie */
void jouerNecrogriffe(Spellwar &grille, char actionJ, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/* BUT : Procedure qui permet de deplacer un eclair du jeu spellwar
 * Prend en parametre la grille de jeu a modifier, iLigne l'indice de la ligne de l'element,
 * iColonne l'indice de la colonne de l'element et adversairesViv le nombre d'adversaires encore en vie */
void deplacerEclair(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

/* BUT : Procedure qui permet de deplacer une flamme du jeu spellwar
 * Prend en parametre la grille de jeu a modifier, iLigne l'indice de la ligne de l'element,
 * iColonne l'indice de la colonne de l'element et adversairesViv le nombre d'adversaires encore en vie */
void deplacerFlamme(Spellwar &grille, unsigned int iLigne, unsigned int iColonne, unsigned int &adversairesViv);

// BUT : Procedure qui permet de mettre a faux deplaceCeTour pour tout les elements du jeu spellwar dans la zone de jeu grille
void reinitialiserDeplacements(Spellwar &grille);

// BUT : Fonction qui retourne un booleen qui vaut vrai si l'element en iLigne iColonne de la zone de jeu grille est un joueur et que deplaceCeTour est faux
bool estJoueurPasDeplCeTour(Spellwar &grille, unsigned int iLigne, unsigned int iColonne);

// BUT : Fonction qui retourne un booleen qui vaut vrai si l'element en iLigne iColonne de la zone de jeu grille est un arcaflamme et que deplaceCeTour est faux
bool estArcaflammePasDeplCeTour(Spellwar &grille, unsigned int iLigne, unsigned int iColonne);

// BUT : Fonction qui retourne un booleen qui vaut vrai si l'element en iLigne iColonne de la zone de jeu grille est un necrogriffe et que deplaceCeTour est faux
bool estNecrogriffePasDeplCeTour(Spellwar &grille, unsigned int iLigne, unsigned int iColonne);

// BUT : Fonction qui retourne un booleen qui vaut vrai si l'element en iLigne iColonne de la zone de jeu grille est un eclair et que deplaceCeTour est faux
bool estEclairPasDeplCeTour(Spellwar &grille, unsigned int iLigne, unsigned int iColonne);

// BUT : Fonction qui retourne un booleen qui vaut vrai si l'element en iLigne iColonne de la zone de jeu grille est une flamme et que deplaceCeTour est faux
bool estFlammePasDeplCeTour(Spellwar &grille, unsigned int iLigne, unsigned int iColonne);

// BUT : Fonction qui retourne un booleen qui vaut vrai si iColonne est egal a l'indice de premiere colonne
bool estSurPremiereColonne(unsigned int iColonne);

// BUT : Fonction qui retourne un booleen qui vaut vrai si iColonne est egal a l'indice de derniere colonne
bool estSurDerniereColonne(unsigned int iColonne);

// BUT : Fonction qui retourne un booleen qui vaut vrai si iLigne est egal a l'indice de premiere ligne ou de derniere ligne
bool estSurPremiereOuDerniereLigne(unsigned int iLigne);

/* BUT : Fonction qui retourne un booleen qui vaut vrai si iColonne est egal a l'indice de premiere colonne et 
iLigne n'est ni egal a l'indice de premiere ligne ni egal a l'indice de derniere ligne */
bool estSurPremiereColonnePasPremiereLignePasDerniereLigne(unsigned int iLigne, unsigned int iColonne);

/* BUT : Procedure qui permet d'afficher un message expliquant la raison de la fin de la partie du jeu spellwar
 * Prend en parametre la zone de jeu grille qui contient la raison de la fin de la partie */
void finirLaPartie(const Spellwar &grille);

#endif // SPELLWAR_H