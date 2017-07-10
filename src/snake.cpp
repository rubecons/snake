/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   snake.cpp
 * Author: ruben
 *
 * Created on 7 avril 2017, 17:12
 * ce qu'il reste à faire :
 *  
 * DONE     une page d'accueil/client où on peut choisir le niveau
 *          mettre le rendu dans un thread (probablement impossible à faire)
 * DONE     gérer les niveaux
 * DONE     faire que les niveaux se lisent dans un fichier
 * DONE     retenir les scores
 *          utiliser des textures
 *          faire différents thèmes de textures(serpent, aliens, lapins, etc...)
 * DONE     mettre des textes pause/victoire/gameover
 * DONE     centrer la map
 * DONE     crypter les scores
 *          ajuster la taille des cotés pour quand on redimensionne la fenetre, ainsi que la page d'accueil
 * DONE     regler le bug de quand il y a un espace vide
 * DONE     regler les scores selon le niveau
 * DONE     ajouter des instructions par-ci par là sous forme de texte
 * DONE     faire du rendu plusieurs couches pour ne pas avoir à recharger tout le rendu à chaque fois
 * DONE     utiliser des singletons pour les moteur, rendu, etats
 * DONE     enlever les commandes inutiles
 * DONE     enlever les commentaires inutiles, relire tous les scripts
 * DONE     replacer le texte correctement
 */

#include <cstdlib>
#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>
#include "etats/Partie.h"
#include "rendu/Rendu.h"
#include "rendu/TileMap.h"
#include "moteur/Moteur.h"

#define DEBUG

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
#ifdef DEBUG
    std::cout<<"Snake - Ruben CONSTANTINI"<<std::endl;
#endif   
    
    etats::Partie::instance();
    moteur::Moteur::instance();
    rendu::Rendu::instance();


    moteur::Moteur::instance().init();

    rendu::Rendu::instance().init();

    return 0;
}

