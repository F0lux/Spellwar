/**
 * @file finirLaPartie.cpp
 * @author Rafael Masson - Arthur Baros
 * @brief Partie du corps du module spellwar.h
 * @date 2023-12-07
 */
#include "spellwar.h"
#include <iostream>

//****************************************************************************
// DEFINITION DES SOUS-PROGRAMMES
//****************************************************************************
void finirLaPartie(const Spellwar &grille)
{
    switch (grille.finJeu)
    {
    case abandon:
        // Afficher en bleu "Vous avez gagne la partie grace a une carte Jackpot !!"
        afficherTexteEnCouleur("Vous avez perdu la partie par abandon", rouge);
        break;
    case mortJoueur:
        // Afficher en rouge "Vous avez perdu la partie par abandon :-("
        afficherTexteEnCouleur("Vous avez perdu la partie par la mort de votre magicien", rouge);
        break;
    case mortAdversaires:
        // Afficher en rouge "Vous avez perdu la partie, il ne reste pas suffisament de carte dans le paquet. :-("
        afficherTexteEnCouleur("Vous avez gagne la partie : tout les ennemis sont morts !", vert);
        break;
    }
}