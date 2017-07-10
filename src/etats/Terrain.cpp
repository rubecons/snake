/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Terrain.h"
#include <iostream>

namespace etats
{
Terrain::Terrain ()
{}

Terrain::~Terrain ()
{}

Terrain::Terrain (int i, int j, Direction orientation, TerrainType terrainT, MurType murT) : Element(i,j,orientation)
{
    this->murType=murT;
    this->terrainType=terrainT;
}

}