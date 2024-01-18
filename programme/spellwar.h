/**
 * @file spellwar.h
 * @author Rafael Masson - Arthur Baros
 * @brief Fichier d'entête du module spellwar
 * @date 2023-01-18
 */
#ifndef SPELLWAR_H
#define SPELLWAR_H

#include "game-tools.h"

const unsigned int TAILLE_LIGNES = 11;       // Largeur de la zone de jeu (de base c'est 35)
const unsigned int TAILLE_COLONNES = 15;     // Hauteur de la zone de jeu (de base c'est 8)
const unsigned int NOMBRES_ADVERSAIRES = 5; // Nombre initial d'adversaires (de base c'est 3)

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

/**
 * @brief Enregistrement caracterisant les differents
 * elements de jeu utilises par le jeu spellwar
 *
 */
struct ElementDeJeu
{
    Entite entite;
    char representation;
    Couleur couleur;
    bool deplaceCeTour = false;
};

enum SituationFinJeu
{
    abandon,
    mortJoueur,
    victoireJoueur
};

struct Spellwar
{
    ElementDeJeu zoneJeu[TAILLE_COLONNES][TAILLE_LIGNES];
    SituationFinJeu finJeu;
};

/**
 * @brief Permet de creer la zone de jeu dans une grille de jeu de spellwar
 *
 * @param [in] grille la grille de jeu a remplir avec les elements de spellwar
 */
void creerZoneJeu(Spellwar &grille);

ElementDeJeu creerJoueur(bool deplCeTour = false);

ElementDeJeu creerArcaflamme(bool deplCeTour = false);

ElementDeJeu creerNecrogriffe(bool deplCeTour = false);

ElementDeJeu creerEclair(bool deplCeTour = false);

ElementDeJeu creerFlamme(bool deplCeTour = false);

ElementDeJeu creerMurVertical();

ElementDeJeu creerMurHorizontal();

ElementDeJeu creerEspaceVide();

ElementDeJeu creerMarqueurCollision();

SituationFinJeu obtenirFinJeu(const Spellwar &grille);

void definirFinJeu(Spellwar &grille, const SituationFinJeu &finJ);

void definirElement(Spellwar& grille, unsigned int iLigne, unsigned int iColonne, ElementDeJeu element);

void jouerUnTour(Spellwar &grille, char actionJ, unsigned int &adversairesViv);

/**
 * @brief Permet de positionner le joueur et les adversaires du jeu spellwar
 *
 * @param [in] grille la grille de jeu a modifier
 */
void positionnerPersonnages(Spellwar &grille);

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