//****************************************************************************
// EN-TETE
//****************************************************************************
/*
 Programme : Spellwar
 But du jeu : Spellwar est un jeu d’arcade dans lequel un joueur incarne un magicien qui affronte des créatures maléfiques.
    Le jeu se déroule dans une zone définie par une certaine hauteur et une certaine largeur.
    Le haut et le bas de la zone de jeu sont délimités par des murs horizontaux et la gauche est délimitée par des murs verticaux mis en place par le magicien.
    Au début du jeu, le joueur est positionné à gauche et au milieu de la zone, juste devant le mur qu’il a mis en place.
    Ces adversaires apparaissent de manière aléatoire sur l’extrémité droite.
   Le joueur peut affronter deux types d’adversaires :
    Des necrogriffes : ce sont des créatures aveugles dont le contact physique est mortel pour le joueur.
    A chaque tour, les necrogriffes progressent vers la gauche du jeu : il peut s’agir d’un déplacement vers la gauche, en haut à gauche ou en bas à gauche.
    Des arcaflammes : ce sont des créatures qui lancent des flammes mortelles pour le joueur.
    Les arcaflammes ne s’approchent pas du joueur et restent toujours sur la bordure droite du jeu.
    A chaque tour, ils peuvent soit se déplacer vers le haut, soit se déplacer vers le bas, soit lancer une flamme.
    Le joueur reste toujours sur la zone gauche du jeu qu’il protège.
   Pour se défendre, le joueur peut, à chaque tour, réaliser une des actions suivantes : monter, descendre ou jeter un éclair magique.
   La partie peut prendre fin de 3 manières différentes :
    abandon du joueur,
    mort du joueur,
    mort de tous les adversaires du joueur.
 Regles du jeu :
    Si le joueur ou un necrogriffe est touché par une flamme jetée par un arcaflamme, il meurt.
    Si un arcaflamme ou un necrogriffe est touché par un éclair du joueur, il meurt.
    Si un necrogriffe percute le mur vertical mis en place au début du jeu par le joueur, il meurt.
    Si un éclair du joueur percute une flamme d’un arcaflamme, les énergies s’annulent (l’éclair et la flamme disparaissent de la zone de jeu).
    Si le joueur, un necrogriffe ou arcaflamme tente traverser le mur horizontal situé en haut ou en bas de la zone de jeu,
    le mouvement est annulé : le joueur / necrogriffe / arcaflamme reste sur place et le tour est considéré comme joué pour lui.
    Si le joueur saisit une action invalide dans sa série de tours, ce tour du joueur uniquement est sauté.
 Date de dernière modification : 18 janvier 2024
 Auteur : R. Masson et A. Baros
 Remarques : Code conforme aux specification internes redigees par notre binome
*/

//****************************************************************************
// INCLUSION
//****************************************************************************
#include <iostream>
#include "game-tools.h"
#include "spellwar.h"
using namespace std;

//****************************************************************************
// PROGRAMME PRINCIPAL
//****************************************************************************
int main(void)
{
    // VARIABLES
    Spellwar plateauJeu;           // Grille du jeu
    bool partieFinie;              // Indicateur de fin de partie
    string actionsSaisieParJ;      // Contient les actions saisies par le joueur
    char actionCourante;           // Contient l'action courante du joueur
    unsigned int adversairesEnVie; // Nombre d'aversaires en vie

    // INITIALISER LA PARTIE

    // Initialiser les variables
    // Initialiser le nombre d'aversaire en vie
    adversairesEnVie = NOMBRES_ADVERSAIRES;
    // Initialiser l'indicateur de fin de partie
    partieFinie = false;

    // Initialiser le tableau
    creerZoneJeu(plateauJeu);

    // Positionner le joueur et les adversaires
    positionnerPersonnages(plateauJeu);

    // JOUER LA PARTIE
    do
    {
        // Afficher la zone de jeu et les actions possibles
        afficherPlateauEtInformations(plateauJeu);

        // Saisir les actions
        cout << "Vos actions : ";
        cin >> actionsSaisieParJ;

        effacer();
        // Jouer toutes les actions et verifier si la partie est finie
        for (unsigned int indiceAction = 0; indiceAction < static_cast<unsigned int>(actionsSaisieParJ.size()); indiceAction++)
        {
            // Affecter a actionCourante l'action courante de la saisie du joueur
            actionCourante = actionsSaisieParJ[indiceAction];

            // Jouer un tour
            jouerUnTour(plateauJeu, actionCourante, adversairesEnVie);

            // Afficher la zone de jeu et les actions possibles
            afficherPlateauEtInformations(plateauJeu);
            // Afficher les actions que le joueur a saisi
            cout << "Vos actions : " << actionsSaisieParJ << endl
                 << endl;

            // Supprimer les marques de collision
            supprimerMarqueCollision(plateauJeu);

            // Tester si la partie est finie
            if (obtenirFinJeu(plateauJeu) == abandon)
            {
                partieFinie = true;
                break;
            }
            if (obtenirFinJeu(plateauJeu) == mortJoueur)
            {
                partieFinie = true;
                break;
            }
            if (adversairesEnVie == 0)
            {
                definirFinJeu(plateauJeu, victoireJoueur);
                partieFinie = true;
                break;
            }
            pause(1);
            effacer();

            // Remettre tout les indicateurs deplaceCeTour des cases de plateauJeu a faux
            reinitialiserDeplacements(plateauJeu);
        }
    } while (!partieFinie);

    // FINIR LA PARTIE
    finirLaPartie(plateauJeu);

    return 0;
}