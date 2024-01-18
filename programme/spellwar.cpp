/**
 * @file spellwar.cpp
 * @author Rafael Masson - Arthur Baros
 * @brief Partie du corps du module spellwar.h
 * @date 2023-01-16
 */
#include "spellwar.h"

ElementDeJeu creerJoueur(bool deplCeTour)
{
    ElementDeJeu resultat;

    // tester si l'element s'est deplace ce tour
    if (deplCeTour)
    {
        resultat = {joueur, 'J', cyan, true};
    }
    else
    {
        resultat = {joueur, 'J', cyan, false};
    }

    // retourner l'element
    return resultat;
}

ElementDeJeu creerArcaflamme(bool deplCeTour)
{
    ElementDeJeu resultat;

    // tester si l'element s'est deplace ce tour
    if (deplCeTour)
    {
        resultat = {arcaflamme, 'A', jaune, true};
    }
    else
    {
        resultat = {arcaflamme, 'A', jaune, false};
    }

    // retourner l'element
    return resultat;
}

ElementDeJeu creerNecrogriffe(bool deplCeTour)
{
    ElementDeJeu resultat;

    // tester si l'element s'est deplace ce tour
    if (deplCeTour)
    {
        resultat = {necrogriffe, 'N', violet, true};
    }
    else
    {
        resultat = {necrogriffe, 'N', violet, false};
    }

    // retourner l'element
    return resultat;
}

ElementDeJeu creerEclair(bool deplCeTour)
{
    ElementDeJeu resultat;

    // tester si l'element s'est deplace ce tour
    if (deplCeTour)
    {
        resultat = {eclair, '>', cyan, true};
    }
    else
    {
        resultat = {eclair, '>', cyan, false};
    }

    // retourner l'element
    return resultat;
}

ElementDeJeu creerFlamme(bool deplCeTour)
{
    ElementDeJeu resultat;

    // tester si l'element s'est deplace ce tour
    if (deplCeTour)
    {
        resultat = {flamme, '<', jaune, true};
    }
    else
    {
        resultat = {flamme, '<', jaune, false};
    }

    // retourner l'element
    return resultat;
}

ElementDeJeu creerMurVertical()
{
    // retourner l'enregistrement du murVertical
    return {murVertical, '|', cyan, false};
}

ElementDeJeu creerMurHorizontal()
{
    // retourner l'enregistrement du murHorizontal
    return {murHorizontal, '#', blanc, false};
}

ElementDeJeu creerEspaceVide()
{
    // retourner l'enregistrement de l'espaceVide
    return {espaceVide, ' ', blanc, false};
}

ElementDeJeu creerMarqueurCollision()
{
    // retourner l'enregistrement de l'espaceVide
    return {marqueurCollision, 'X', rouge, false};
}

SituationFinJeu obtenirFinJeu(const Spellwar &grille)
{
    // Retourner la raison de la fin de la partie
    return grille.finJeu;
}

void definirFinJeu(Spellwar &grille, const SituationFinJeu &finJ)
{
    // Definir la fin de la partie a finJ
    grille.finJeu = finJ;
}

void definirElement(Spellwar& grille, unsigned int iLigne, unsigned int iColonne, ElementDeJeu element)
{
    // Definir l'element en iLigne iColonne de la zone de jeu grille a element
    grille.zoneJeu[iLigne][iColonne] = element;
}