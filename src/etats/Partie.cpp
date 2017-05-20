/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include <random>
#include "Partie.h"
#include "Serpent.h"

#include "moteur/CommandePlayPause.h"


namespace etats{

Partie::Partie (): points(0), duree(0), niveau(1), play(true)
{
    
}

Partie::~Partie ()
{
    
}

void Partie::nouvellePartie (int niv)
{
    
    factory = new ElementFactory;
    bool isSerpent=false;
    std::string niveau;
    int m=0, i=0, j=0;
    //Terrain* inst;
    
    largeur=0;
    
    switch(niv)
    {
        case 1 : niveau="p----------q\n|          |\n|          |\n|          |\n|     s    |\n|          |\n|          |\n|          |\n|          |\n|          |\n|          |\nb----------d";
            break;
        case 2 : niveau="p----q\n|  s |\n| p--d\n| |\n| b--q\n|    |\nb----d";
            break;
        case 3 : 
            break;
    }
    
    while(niveau[m]!='\0')
    {//std::cout<<j<<std::endl;
        if(j>largeur && niveau[m]!='\n')largeur=j;
        j++;
        if(niveau[m]=='\n')
        {
            
            j=0;i++;
        }
        m++;
       
    }
    hauteur=i+1;largeur++;
    std::cout<<"hauteur "<< hauteur<<"   largeur"<<largeur<<std::endl;
    terrain.resize(hauteur*largeur);
    std::cout<<terrain.size()<<std::endl;
    serpent->corps.resize(hauteur*largeur);
    //std::cout<<hauteur*largeur<<std::endl;
    m=0;j=0;i=0;
    indexTerrain = 0;
    
    while(niveau[m]!='\0')
    {
        if(niveau[m]=='\n')
        {
            j=0;i++;m++;
            continue;
        }
        
        if(niveau[m]!='\n' || niveau[m]!='v') //le carctère v est le vide avant une barrière de gauche, histoire de ne pas créer une case terrain espace
        {
            //Terrain terr = terrain[indexTerrain];
            //terr=factory->newInstance(niveau[m], i, j);
            //terrain.push_back(terr);
            
            terrain[indexTerrain]=factory->newInstance(niveau[m], i, j);
            //std::cout<<niveau[m]<<"   i: "<<i<<"   j: "<<j<<"      terrain["<<indexTerrain<<"]  i : "<< terrain[indexTerrain]->i<<"   j: "<<terrain[indexTerrain]->j <<std::endl;
            indexTerrain++;
        }
        
        
        if(niveau[m]=='s')
        {
            isSerpent=true;
            serpent= new Serpent(i,j,Direction::EST, niv, this);
            ElementCorps* tete = new ElementCorps(i, j, Direction::EST, true);
            serpent->corps.push_back(tete);
        }
        j++;
        
        
        m++;
       
    }
    
    if(isSerpent)
    {
        serpent->placerQueue();
    }
       
    placerFruit();
   // std::cout<<"hauteur "<<hauteur<<"    largeur "<<largeur<<std::endl;
//    for(unsigned int d =0 ; d < indexTerrain; d++)
//    {
//        std::cout<<"i "<<terrain[d]->i<<"   j "<<terrain[d]->j<<"   terrType "<<terrain[d]->terrainType<<std::endl;
//    }
    
    
//    std::cout<<"test fct partie"<<std::endl;
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

void Partie::placerFruit()
{
    int fi=0, fj=0;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> haut(0,hauteur);
    std::uniform_int_distribution<int> larg(0,largeur);
    while(terrain[fj + (fi*largeur)]->terrainType==TerrainType::MUR || serpent->isSerpent(fi, fj, false))
    {
        fi = haut(generator); 
        fj = larg(generator);
    }
    
    fruit[0]=fi;
    fruit[1]=fj;
}

void Partie::finPartie(FinPartie fin)
{moteur->ajouterCommande(new moteur::CommandePlayPause(this));
    std::cout<<"fin de partie"<<std::endl;
}

void Partie::pause()
{
    play=false;
}

void Partie::reprendre()
{
    play=true;
}

}