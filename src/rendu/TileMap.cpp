/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TileMap.cpp
 * Author: ruben
 * 
 * Created on 16 mai 2017, 14:21
 */

//#include "TileMap.h"
#include "../etats/Terrain.h"
#include "etats/Partie.h"
#include "etats/Serpent.h"
#include <cmath>
//#include "Partie.h"



namespace rendu
{
    
TileMap::TileMap() {
}

TileMap::TileMap(const TileMap& orig) {
}

TileMap::~TileMap() {
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    // on applique la texture du tileset
    states.texture = &imageTexture;

    // et on dessine enfin le tableau de vertex
    target.draw(tableauVertex, states);
}

bool TileMap::init(sf::RenderWindow* wind, unsigned int width, unsigned int height)
{
    isTexture=true;
    
        
    std::string tileset = "";

    if(tileset.empty())
    {
        isTexture=false;
        imageTexture.~Texture();
    }
    else if(!imageTexture.loadFromFile(tileset))
    {
        isTexture=false;
    }
    
    tableauTerrain.setPrimitiveType(sf::Quads);
    tableauTerrain.resize(etats::Partie::instance().largeur*etats::Partie::instance().hauteur*4);
    tableauVertex.setPrimitiveType(sf::Quads);
    tableauVertex.resize(etats::Partie::instance().largeur*etats::Partie::instance().hauteur*4);
    
    majTerrain();
    
    return true;
}

void TileMap::majTerrain()
{
    const std::vector<etats::Terrain*> terrain= etats::Partie::instance().terrain;
    
    unsigned int x = rendu::Rendu::instance().wind->getSize().x; //largeur
    unsigned int y = rendu::Rendu::instance().wind->getSize().y; //hauteur
    
    float width = rendu::Rendu::instance().L;
    
    int tailleCote = (int)std::fmin((float)(x/rendu::Rendu::instance().H),(float)(y/width));

    
    for(unsigned int i=0; i<etats::Partie::instance().indexTerrain; i++)
    {
        
        etats::Terrain* terr = terrain[i];
        
        sf::Vertex* quad = &tableauTerrain[(terr->j + terr->i * width) * 4];
        
        quad[0].position = sf::Vector2f(terr->j * tailleCote, terr->i * tailleCote);
        quad[1].position = sf::Vector2f((terr->j+ 1) * tailleCote, terr->i * tailleCote);
        quad[2].position = sf::Vector2f((terr->j + 1) * tailleCote, (terr->i + 1) * tailleCote);
        quad[3].position = sf::Vector2f(terr->j * tailleCote, (terr->i + 1) * tailleCote);
//        quad[0].position = sf::Vector2f(terr->j * tileSize.x, terr->i * tileSize.y);
//        quad[1].position = sf::Vector2f((terr->j+ 1) * tileSize.x, terr->i * tileSize.y);
//        quad[2].position = sf::Vector2f((terr->j + 1) * tileSize.x, (terr->i + 1) * tileSize.y);
//        quad[3].position = sf::Vector2f(terr->j * tileSize.x, (terr->i + 1) * tileSize.y);

        
        if(isTexture)
        {
            int tu = terr->terrainType % (imageTexture.getSize().x / tailleCote);
            int tv = terr->terrainType / (imageTexture.getSize().x / tailleCote);
//            int tu = terr->terrainType % (imageTexture.getSize().x / tileSize.x);
//            int tv = terr->terrainType / (imageTexture.getSize().x / tileSize.x);
        
            // on définit ses quatre coordonnées de texture
            quad[0].texCoords = sf::Vector2f(tu * tailleCote, tv * tailleCote);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tailleCote, tv * tailleCote);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tailleCote, (tv + 1) * tailleCote);
            quad[3].texCoords = sf::Vector2f(tu * tailleCote, (tv + 1) * tailleCote);
//            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
//            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
//            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
//            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
        else
        {
            quad[0].color = couleurs[terr->terrainType];
            quad[1].color = couleurs[terr->terrainType];
            quad[2].color = couleurs[terr->terrainType];
            quad[3].color = couleurs[terr->terrainType];
        }
    }
}

bool TileMap::load(sf::Vector2u tileSize, unsigned int width, unsigned int height)
{
    std::vector<etats::ElementCorps*> corps = etats::Partie::instance().serpent->corps;
    tableauVertex=tableauTerrain;
    
    
    
    for(int i=0; i<etats::Partie::instance().serpent->tailleCorps; i++)
    {
        etats::ElementCorps* co = corps[i];
        if(co->visible==false)break;
        
        sf::Vertex* quad = &tableauVertex[(co->j + co->i * width) * 4];
        quad[0].position = sf::Vector2f(co->j * tileSize.x, co->i * tileSize.y);
        quad[1].position = sf::Vector2f((co->j+ 1) * tileSize.x, co->i * tileSize.y);
        quad[2].position = sf::Vector2f((co->j + 1) * tileSize.x, (co->i + 1) * tileSize.y);
        quad[3].position = sf::Vector2f(co->j * tileSize.x, (co->i + 1) * tileSize.y);
        
        if(isTexture)
        {
            int tu = 3 % (imageTexture.getSize().x / tileSize.x);
            int tv = 3 / (imageTexture.getSize().x / tileSize.x);
        
            // on définit ses quatre coordonnées de texture
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
        else
        {
            quad[0].color = couleurs[4];
            quad[1].color = couleurs[4];
            quad[2].color = couleurs[4];
            quad[3].color = couleurs[4];
        }
        
    }
    
    {
        int fruitI=etats::Partie::instance().fruit[0];
        int fruitJ=etats::Partie::instance().fruit[1];
        
        sf::Vertex* quad = &tableauVertex[(fruitJ + fruitI * width) * 4];
        quad[0].position = sf::Vector2f(fruitJ * tileSize.x, fruitI * tileSize.y);
        quad[1].position = sf::Vector2f((fruitJ+ 1) * tileSize.x, fruitI * tileSize.y);
        quad[2].position = sf::Vector2f((fruitJ + 1) * tileSize.x, (fruitI + 1) * tileSize.y);
        quad[3].position = sf::Vector2f(fruitJ * tileSize.x, (fruitI + 1) * tileSize.y);
        
        if(isTexture)
        {//std::cout<<"test"<<i<<"3"<<std::endl;
            int tu = 3 % (imageTexture.getSize().x / tileSize.x);
            int tv = 3 / (imageTexture.getSize().x / tileSize.x);
        
            // on définit ses quatre coordonnées de texture
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
        else
        {
            quad[0].color = couleurs[2];
            quad[1].color = couleurs[2];
            quad[2].color = couleurs[2];
            quad[3].color = couleurs[2];
        }
        
    }
    
    
    return true;
}

};