/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TileMap.h
 * Author: ruben
 *
 * Created on 16 mai 2017, 14:21
 */

#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics.hpp>
#include <array>
#include <string>
#include "etats/Partie.h"
#include <iostream>
namespace etats
{
    class Terrain;
    class Partie;
    class Serpent;
}

namespace rendu
{

class TileMap : public sf::Drawable, public sf::Transformable{

public:
    TileMap();
    TileMap(const TileMap& orig);
    virtual ~TileMap();
    bool init(sf::RenderWindow *wind, unsigned int width, unsigned int height);
    void majTerrain();
    bool load(sf::Vector2u tileSize, unsigned int width, unsigned int height);

private:
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    sf::VertexArray tableauTerrain, tableauVertex;
    sf::Texture imageTexture;
    bool isTexture;
    std::array<sf::Color, 5> couleurs = {sf::Color::Yellow, sf::Color::Blue, sf::Color::Red, sf::Color::Black,sf::Color::Green};
};

};
#endif /* TILEMAP_H */

