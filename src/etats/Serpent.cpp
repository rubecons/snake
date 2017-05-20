/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Serpent.h"

#include <iostream>

namespace etats
{
    
Serpent::Serpent ()
{}

Serpent::Serpent (int i, int j, Direction orientation, int vitesse, Partie* part) : Element(i, j,orientation)
{
    this->vitesse=vitesse;
    partie=part;
    //std::cout<<"serpent"<<i<<"  "<<j<<"  orientation"<< orientation<<"  vitesse "<<vitesse<<std::endl;
}

Serpent::~Serpent ()
{}

void Serpent::avancer ()
{
    int iBuffer=corps.front()->i, jBuffer=corps.front()->j, iBuf, jBuf;
    //bool visibleBuffer=;
    Direction orientationBuffer=corps.front()->orientation, orientationBuf;
    
    switch(orientation)
    {
        case Direction::EST : corps.front()->j++;
            break;
        case Direction::NORD : corps.front()->i--;
            break;
        case Direction::SUD : corps.front()->i++;
            break;
        case Direction::OUEST : corps.front()->j--;
            break;
        default :
            break;
    }

    
    for(size_t m=1 ; m<corps.size(); m++)
    {
        iBuf=corps[m]->i, jBuf=corps[m]->j; orientationBuf=corps[m]->orientation;
        corps[m]->i=iBuffer;
        corps[m]->j=jBuffer;
        corps[m]->orientation=orientationBuffer;
        
     iBuffer=iBuf;jBuffer=jBuf;orientationBuffer=orientationBuf;   
    }
    
    if(corps.front()->i==partie->fruit[0] && corps.front()->j==partie->fruit[1])
    {
        grandir();
        partie->placerFruit();
    }
    else if(partie->terrain[corps.front()->j + (corps.front()->i * partie->largeur)]->terrainType==TerrainType::MUR || isSerpent(corps.front()->i, corps.front()->j, true))
    {
        partie->finPartie(FinPartie::GAMEOVER);
    }
}

void Serpent::tourner (Direction dir)
{
    if((orientation==Direction::EST && dir!=Direction::OUEST) || (orientation==Direction::NORD && dir!=Direction::SUD) || (orientation==Direction::SUD && dir!=Direction::NORD) || (orientation==Direction::OUEST && dir!=Direction::EST))
    {
        orientation=dir;
    }
}

bool Serpent::isSerpent(int i, int j, bool serpentSansTete) //permet de savoir si des coordonnées sont dans le serpent ou pas
{
    for(size_t k=serpentSansTete; k< corps.size(); k++)
    {
        if(corps[k]->i==i && corps[k]->j==j)
        {
            return true;
        }
    }
    return false;
}
    
void Serpent::grandir()
{
    corps.back()->visible=true;
    
    placerQueue();
}

void Serpent::placerQueue()
{
    Direction orientation = corps.back()->orientation;
        int i2 = corps.back()->i;
        int j2 = corps.back()->j;
        switch(orientation)
        {
            case Direction::EST:
        
            j2--;break;
        
            case Direction::NORD:
        
            i2++;break;
        
            case Direction::OUEST:
        
            j2++;break;
        
            case Direction::SUD:
        
            i2--;break;
            default :
                break;
        }

        ElementCorps* fin = new ElementCorps(i2, j2, orientation, false);
        corps.push_back(fin);
}

}