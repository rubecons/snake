/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PageAccueil.cpp
 * Author: ruben
 * 
 * Created on 2 juin 2017, 21:17
 */

//#include "PageAccueil.h"
#include "Rendu.h"
#include <cmath>
#include <SFML/Window/Event.hpp>

namespace rendu
{

PageAccueil::PageAccueil() {
}

PageAccueil::PageAccueil(const PageAccueil& orig) {
}

PageAccueil::~PageAccueil() {
}

void PageAccueil::init()
{

    fond.init();
    
    /*jouer = new sf::Text();               jouer.setFont(font);jouer.setString("jouer !");jouer.setFillColor(sf::Color::White);jouer.setPosition(30, 500);
    facile= new sf::Text();               facile.setFont(font);facile.setString("facile");facile.setFillColor(sf::Color::White);facile.setPosition(30, 650);
    moyen = new sf::Text();               moyen.setFont(font);moyen.setString("moyen");moyen.setFillColor(sf::Color::White);moyen.setPosition(100,690 );
    difficile = new sf::Text();           difficile.setFont(font);difficile.setString("difficile");difficile.setFillColor(sf::Color::White);difficile.setPosition(200,730);
    instructionAccueil = new sf::Text();  instructionAccueil.setFont(font);instructionAccueil.setString("appuyer sur entree pour sélectionner un choix\ndeplacez vous dans le menu a l'aide des fleches directionnelles\ndeplacez le serpent a l'aide des fleches directionnelles\nappuyer sur ECHAP pour mettre le jeu en pause");instructionAccueil.setCharacterSize(17);instructionAccueil.setFillColor(sf::Color::White);instructionAccueil.setPosition(30,350);
    */
    fenetre=rendu::Rendu::instance().wind;
    niveau=0;
    
    curseur[0]=0;
    curseur[1]=0;

}

void PageAccueil::enregisrerNiveauViaCurseur()
{
    niveau=curseur[1];
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FondAccueil::init()
{
    fenetre=rendu::Rendu::instance().wind;
    
    if(!imageAccueil.loadFromFile("ressources/accueil.png"))
    {
        std::cout<<"impossible de charger l'image de la page d'accueil"<<std::endl;
    }
    
    quad.setPrimitiveType(sf::Quads);
    quad.resize(4);
    
    quad[0].position = sf::Vector2f(0, 0);
    quad[1].position = sf::Vector2f(800, 0);
    quad[2].position = sf::Vector2f(800, 800);
    quad[3].position = sf::Vector2f(0, 800);

    // et on définit la zone de texture à lui appliquer comme étant le rectangle de 25x50 démarrant en (0, 0)
    quad[0].texCoords = sf::Vector2f(0, 0);
    quad[1].texCoords = sf::Vector2f(800, 0);
    quad[2].texCoords = sf::Vector2f(800, 800);
    quad[3].texCoords = sf::Vector2f(0, 800);
}

//void FondAccueil::resizeFond()//sf::Event::SizeEvent size)
//{
//    //fenetre=rendu::Rendu::instance().wind;
//    //int carre = std::fmin(size.height, size.width); //std::cout<<"height  "<<size.height<<"    width "<<size.width<<"    carre"<<carre<<std::endl;
//    int carre = std::fmin(rendu::Rendu::instance().wind->getSize().y, rendu::Rendu::instance().wind->getSize().x);
//    
//    
//    quad[0].position = sf::Vector2f(0, 0);
//    quad[1].position = sf::Vector2f(carre, 0);
//    quad[2].position = sf::Vector2f(carre, carre);
//    quad[3].position = sf::Vector2f(0, carre);
//}

void FondAccueil::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // on applique la transformation de l'entité -- on la combine avec celle qui a été passée par l'appelant
    states.transform *= getTransform();

    // on applique la texture
    states.texture = &imageAccueil;

    // on peut aussi surcharger states.shader ou states.blendMode si nécessaire

    // on dessine le tableau de vertex
    target.draw(quad, states);
}



}