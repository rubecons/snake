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

#include "TileMap.h"
#include "../etats/Terrain.h"
#include "etats/Partie.h"
#include "etats/Serpent.h"
//#include "Partie.h"
#include <iostream>


namespace rendu
{
    
TileMap::TileMap() {
    
//    couleurs[0]=sf::Color::Blue;
//    couleurs[1]=sf::Color::Cyan;
//    couleurs[2]=sf::Color::Red;
//    couleurs[3]=sf::Color::Green;
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

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize,etats::Partie* partie, unsigned int width, unsigned int height)
{
    const std::vector<etats::Terrain*> terrain= partie->terrain;
    std::vector<etats::ElementCorps*> corps = partie->serpent->corps;
    bool isTexture=true;
    //std::cout<<tileset.empty()<<std::endl;
    if(tileset.empty())
    {
        isTexture=false;
        imageTexture.~Texture();
    }
    else if(!imageTexture.loadFromFile(tileset))
    {
        return false;
    }
        
    tableauVertex.setPrimitiveType(sf::Quads);
    tableauVertex.resize(width*height*4);
    //std::cout<< width*height*4<< std::endl;
    
    //std::cout<<"test1"<<std::endl;
    
    for(unsigned int i=0; i<partie->indexTerrain; i++)
    {
        
        etats::Terrain* terr = terrain[i];
        //std::cout<<"i "<<terr->i<<"   j "<<terr->j<<"   terrType "<<terr->terrainType<<std::endl;
        //std::cout<<(terr->j + terr->i * width) * 4 <<std::endl;
      
      //std::cout<<terr->terrainType<<"   "<<(terr->j + terr->i * width) << "  sur  "<< width*height<< std::endl;
        // on récupère un pointeur vers le quad à définir dans le tableau de vertex
        sf::Vertex* quad = &tableauVertex[(terr->j + terr->i * width) * 4];
        //std::cout<<"test"<<i<<"1"<<std::endl;
        // on définit ses quatre coins
        quad[0].position = sf::Vector2f(terr->j * tileSize.x, terr->i * tileSize.y);
        quad[1].position = sf::Vector2f((terr->j+ 1) * tileSize.x, terr->i * tileSize.y);
        quad[2].position = sf::Vector2f((terr->j + 1) * tileSize.x, (terr->i + 1) * tileSize.y);
        quad[3].position = sf::Vector2f(terr->j * tileSize.x, (terr->i + 1) * tileSize.y);
//std::cout<<"test"<<i<<"2"<<std::endl;
        
        if(isTexture)
        {//std::cout<<"test"<<i<<"3"<<std::endl;
            int tu = terr->terrainType % (imageTexture.getSize().x / tileSize.x);
            int tv = terr->terrainType / (imageTexture.getSize().x / tileSize.x);
        
            // on définit ses quatre coordonnées de texture
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
        else
        {//std::cout<<"test"<<i<<"4"<<std::endl;
            quad[0].color = couleurs[terr->terrainType];
            quad[1].color = couleurs[terr->terrainType];
            quad[2].color = couleurs[terr->terrainType];
            quad[3].color = couleurs[terr->terrainType];
        }
//std::cout<<"test"<<i<<"5"<<std::endl;
    }
    
    for(unsigned int i=0; i<partie->serpent->corps.size(); i++)
    {
        etats::ElementCorps* co = corps[i];
        if(co->visible==false)break;
        
        sf::Vertex* quad = &tableauVertex[(co->j + co->i * width) * 4];
        quad[0].position = sf::Vector2f(co->j * tileSize.x, co->i * tileSize.y);
        quad[1].position = sf::Vector2f((co->j+ 1) * tileSize.x, co->i * tileSize.y);
        quad[2].position = sf::Vector2f((co->j + 1) * tileSize.x, (co->i + 1) * tileSize.y);
        quad[3].position = sf::Vector2f(co->j * tileSize.x, (co->i + 1) * tileSize.y);
        
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
        {//std::cout<<"test"<<i<<"4"<<std::endl;
            quad[0].color = couleurs[3];
            quad[1].color = couleurs[3];
            quad[2].color = couleurs[3];
            quad[3].color = couleurs[3];
        }
        
    }
    return true;
//    std::cout<<"test30"<<std::endl;
}

};