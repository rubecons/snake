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

Serpent::Serpent (int i, int j, Direction orientation, int vitesse) : Element(i, j,orientation)
{ this->i=i; this->j=j;
    this->vitesse=vitesse;
    tailleCorps=0;
}

Serpent::~Serpent ()
{}

void Serpent::avancer ()
{
    int iBuffer=corps.front()->i, jBuffer=corps.front()->j, iBuf, jBuf;
    Direction orientationBuffer=corps.front()->orientation, orientationBuf;
    
    switch(orientationBuffer)
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

    
    for(int m=1 ; m<tailleCorps; m++)
    {
        iBuf=corps[m]->i, jBuf=corps[m]->j; orientationBuf=corps[m]->orientation;
        corps[m]->i=iBuffer;
        corps[m]->j=jBuffer;
        corps[m]->orientation=orientationBuffer;
        
     iBuffer=iBuf;jBuffer=jBuf;orientationBuffer=orientationBuf;   
    }
    
    if(corps.front()->i==etats::Partie::instance().fruit[0] && corps.front()->j==etats::Partie::instance().fruit[1])
    {

        grandir();
        etats::Partie::instance().placerFruit();
    }
    else if(etats::Partie::instance().terrain[corps.front()->j + (corps.front()->i * etats::Partie::instance().largeur)]->terrainType==TerrainType::MUR || isSerpent(corps.front()->i, corps.front()->j, true))
    {
        
        etats::Partie::instance().finPartie(FinPartie::GAMEOVER);
    }
}

void Serpent::tourner (Direction dir)
{
    if((corps.front()->orientation==Direction::EST && dir!=Direction::OUEST) || (corps.front()->orientation==Direction::NORD && dir!=Direction::SUD) || (corps.front()->orientation==Direction::SUD && dir!=Direction::NORD) || (corps.front()->orientation==Direction::OUEST && dir!=Direction::EST))
    {
        corps.front()->orientation=dir;
    }
}

bool Serpent::isSerpent(int i, int j, bool serpentSansTete) //permet de savoir si des coordonnées sont dans le serpent ou pas
{
    for(int k=serpentSansTete; k< tailleCorps-1; k++)
    {
        if(corps[k]->i==i && corps[k]->j==j && corps[k]->visible)
        {
            return true;
        }
    }
    return false;
}
    
void Serpent::grandir()
{
    corps[tailleCorps-1]->visible=true;
    etats::Partie::instance().points++;
    placerQueue();
}

void Serpent::placerQueue()
{   if(tailleCorps==(int)corps.size())etats::Partie::instance().finPartie(FinPartie::VICTOIRE);
    
    
    Direction orientation = corps[tailleCorps-1]->orientation;
        int i2 = corps[tailleCorps-1]->i;
        int j2 = corps[tailleCorps-1]->j;
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
        corps[tailleCorps++]=fin;
}

}