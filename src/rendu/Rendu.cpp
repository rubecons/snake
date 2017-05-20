/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Rendu.h"
//#include "etats/Terrain.h"
#include <cmath>
#include <iostream>
#include "etats/Partie.h"
#include "moteur/Moteur.h"
#include "moteur/CommandePlayPause.h"
#include "moteur/CommandeTourner.h"
#include "moteur/CommandeAvancer.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

//#include <iostream>

namespace rendu
{
    
Rendu::Rendu()
{}

Rendu::~Rendu()
{}

void Rendu::init(etats::Partie* part)
{
    moteur=part->moteur;
    partie = part;
    
    winX= 800;
    winY= 500;
    H=partie->hauteur;
    L=partie->largeur;
    
    
    map= new TileMap;
    
            
            tailleCote = (int)std::fmin((float)(winX/L),(float)(winY/H));
    
    wind = new sf::RenderWindow(sf::VideoMode(winX, winY), "SnAkE");
    float duree=0;
    
    sf::Clock dt;
    
    
    while (wind->isOpen())
    {
        
        
        sf::Event event;
        while (wind->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed :
                    wind->close();
                    break;
                case sf::Event::LostFocus :
                    partie->pause();
                    moteur->moteurEnabled=false;
                    break;
                case sf::Event::KeyPressed :
                {    switch(event.key.code)
                    {
                        case sf::Keyboard::Escape :
                            moteur->ajouterCommande(new moteur::CommandePlayPause(partie));
                            break;
                        case sf::Keyboard::Up : moteur->ajouterCommande(new moteur::CommandeTourner(partie, etats::Direction::NORD));
                            break;
                        case sf::Keyboard::Down : moteur->ajouterCommande(new moteur::CommandeTourner(partie, etats::Direction::SUD));
                            break;
                        case sf::Keyboard::Right : moteur->ajouterCommande(new moteur::CommandeTourner(partie, etats::Direction::EST));
                            break;
                        case sf::Keyboard::Left : moteur->ajouterCommande(new moteur::CommandeTourner(partie, etats::Direction::OUEST));
                            break;
                        default :
                            break;
                    }
                }
                break;
                //case sf::Event::GainedFocus :
                    
                default : break;
            }
        }

        
        duree=duree+dt.restart().asMilliseconds();
        if(duree>=500)
        {
            moteur->ajouterCommande(new moteur::CommandeAvancer(partie));
            duree=0;
        }
        
        
        wind->clear();
        wind->display();
    }
    update();
}

void Rendu::update()
{
   // TileMap mapp;
    
    
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    //Couche coucheTerrain;
    //unsigned int x = wind->getSize().x; //largeur
    //unsigned int y = wind->getSize().y; //hauteur
    
    
    //std::cout<<tailleCote<<std::endl;
    
    //std::cout<<"x= "<<wind->getSize().x<<"   y= "<<wind->getSize().y<< std::endl;
    
    if(!map->load("", sf::Vector2u((unsigned int)tailleCote, (unsigned int)tailleCote), partie, L, H))
    {exit(-1);}
    
    
    while (wind->isOpen())
    {

        wind->clear();
        wind->draw(*map);
     
        wind->display();
    }
}


};