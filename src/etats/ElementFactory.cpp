/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementFactory.h"



namespace etats
{
    

ElementFactory::ElementFactory ()
{}

ElementFactory::~ElementFactory ()
{}

Terrain* const ElementFactory::newInstance (char c, size_t i, size_t j)
{
    Terrain * elt=nullptr;
    
    switch(c)
    {
        case 'p' :
            elt= new Terrain(i, j, Direction::NORD,TerrainType::MUR, MurType::COIN );
            break;
        case '-':
            elt= new Terrain(i, j, Direction::EST,TerrainType::MUR, MurType::DROIT );
            break;
        case 'q':
            elt= new Terrain(i, j, Direction::EST,TerrainType::MUR, MurType::COIN );
            break;
        case '|':
            elt= new Terrain(i, j, Direction::NORD,TerrainType::MUR, MurType::DROIT );
            break;
        case 's':
            //elt= new Serpent(i, j, Direction::EST);
            elt= new Terrain(i, j, Direction::NON,TerrainType::ESPACE, MurType::NONE );
            break;
        case 'b':
            elt= new Terrain(i, j, Direction::OUEST,TerrainType::MUR, MurType::COIN );
            break;
        case 'd':
            elt= new Terrain(i, j, Direction::SUD,TerrainType::MUR, MurType::COIN );
            break;
        case 'f':
            elt= new Terrain(i, j, Direction::NON,TerrainType::FRUIT, MurType::NONE );
            break;
        case ' ':
            elt= new Terrain(i, j, Direction::NON,TerrainType::ESPACE, MurType::NONE );
            break;
        default :
            elt= new Terrain(i, j, Direction::NON,TerrainType::ESPACE, MurType::NONE );
            break;
    }
    
    return elt;
}

}