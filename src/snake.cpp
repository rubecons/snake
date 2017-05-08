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
 */

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "etats/Partie.h"

#define DEBUG

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
#ifdef DEBUG
    std::cout<<"Snake - Ruben CONSTANTINI"<<std::endl;
#endif   
    
    etats::Partie partie;
    partie.nouvellePartie(1);
 
   sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    
    return 0;
}

