/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include "Partie.h"
#include "Serpent.h"


namespace etats{

Partie::Partie (): points(0), duree(0), niveau(1)
{
    factory = new ElementFactory;
}

Partie::~Partie ()
{
    
}

void Partie::nouvellePartie (int niv)
{
    std::string niveau;
    size_t m=0, i=0, j=0;
    Terrain* inst;
    
    switch(niv)
    {
        case 1 : niveau="p--q\n|cs|\nb--d";
            break;
        case 2 : 
            break;
        case 3 : 
            break;
    }

    while(niveau[m]!='\0')
    {
        
        //std::cout<<niveau[m]<<"   i: "<<i<<"   j: "<<j<<std::endl;
        if(niveau[m]!='\n')
        {
            inst=factory->newInstance(niveau[m], i, j);
            terrain.push_back(inst);
        }
        if(niveau[m]=='s')
        {
            serpent= new Serpent(i,j,Direction::EST, niv);
            ElementCorps* tete = new ElementCorps(i, j, Direction::EST, true);
            serpent->corps.push_back(tete);
        }
        j++;
        
        if(niveau[m]=='\n')
        {
            j=0;i++;
        }
        m++;
       
    }
    
    Direction orientation = serpent->corps.back()->orientation;
    int i2 = serpent->corps.back()->i;
    int j2 = serpent->corps.back()->j;
    if(orientation==Direction::EST)
    {
        j2--;
    }
    else if(orientation==Direction::NORD)
    {
        i2++;
    }
    else if(orientation==Direction::OUEST)
    {
        j2++;
    }
    else if(orientation==Direction::SUD)
    {
        i2--;
    }
    
    ElementCorps* fin = new ElementCorps(i2, j2, orientation, false);
    serpent->corps.push_back(fin);
    
}

int Partie::getPoints ()
{
    return points;
}

float Partie::getDuree ()
{
    return duree;
}

int Partie::getNiveau ()
{
    return niveau;
}

void Partie::setPoints (int points)
{
    
}

}