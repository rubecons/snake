/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include "Partie.h"
#include "Serpent.h"
#include <cstdlib>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>


namespace etats{

Partie::Partie (): points(0), duree(0), niveau(1), play(false), fin(FinPartie::NOP)
{
    factory = new ElementFactory;
}

Partie::~Partie ()
{
    
}

Partie & Partie::instance()
{
    static Partie partie;
    return partie;
}

void Partie::nouvellePartie (int niv)
{
    play=true;
    fin=FinPartie::NOP;
    bool isSerpent=false;
    niveau=niv;
    
    std::string nivea;
    int m=0, i=0, j=0;

    
    largeur=0;

    nivea=lectureFichierNiveau(niveau);
    
    while(nivea[m]!='\0')
    {
        if(j>largeur && nivea[m]!='\n')largeur=j;
        
        j++;
        if(nivea[m]=='\n')
        {
            
            j=0;i++;
        }
        m++;
       
    }
    hauteur=i+1;
    largeur++;
    
    terrain.resize(hauteur*largeur);
    
    m=0;j=0;i=0;
    indexTerrain = 0;
    
    while(nivea[m]!='\0')
    {
        if(nivea[m]=='\n')
        {
            j=0;i++;m++;
            continue;
        }
        
        if(nivea[m]!='\n' || nivea[m]!='v') //le carctère v est le vide avant une barrière de gauche, histoire de ne pas créer une case terrain espace
        {    
            terrain[indexTerrain]=factory->newInstance(nivea[m], i, j);
            indexTerrain++;
        }
        
        
        if(nivea[m]=='s')
        {
            isSerpent=true;
            serpent= new Serpent(i,j,Direction::EST, niv);
            serpent->corps.resize(hauteur*largeur);
            ElementCorps* tete = new ElementCorps(i, j, Direction::EST, true);
            serpent->corps[serpent->tailleCorps++]=tete;
        }
        j++;
        m++;
       
    }
    
    if(isSerpent)
    {
        serpent->corps.resize(factory->nombreEspace);
        serpent->placerQueue();
    }
       
    placerFruit();
    
    rendu::Rendu::instance().H=hauteur;
    rendu::Rendu::instance().L=largeur;
    
}

void Partie::quitterPartie()
{
    for(ElementCorps*& cor : serpent->corps)
    {
        cor->~ElementCorps();
    }
    serpent->~Serpent();
    points=0;
    niveau=0;
    for(Terrain*& ter : terrain)
    {
        ter->~Terrain();
    }
    terrain.clear();
    hauteur=0;
    largeur=0;
    indexTerrain=0;
    play=false;
    fin=FinPartie::NOP;
}

std::string Partie::lectureFichierNiveau(int niveau)
{
    std::string niveauSurLigne, ligneImportee,fichier="ressources/niveau"+std::to_string(niveau);
    std::ifstream lectureNiveau;
    
    lectureNiveau.open(fichier);
    
    if(lectureNiveau.is_open()==false)
    {
        std::cout<<"impossible de trouver un niveau"<<std::endl;exit(1);
    }
    else
    {
        while(std::getline(lectureNiveau, ligneImportee))
        {
            niveauSurLigne+=ligneImportee;
            if(!lectureNiveau.eof()){niveauSurLigne+='\n';}
            
        }niveauSurLigne.pop_back();niveauSurLigne.push_back('\0');
    }
    lectureNiveau.close();
    return niveauSurLigne;
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

    while(terrain[fj + (fi*largeur)]->terrainType!=TerrainType::ESPACE || serpent->isSerpent(fi, fj, false))
    {
        fi =  1 + std::rand()%(hauteur-2);
        fj =  1 + std::rand()%(largeur-2);
    }
    
    fruit[0]=fi;
    fruit[1]=fj;
}

void Partie::finPartie(FinPartie fin)
{
    pause();
    this->fin=fin;
    rendu::Rendu::instance().actualiserScores();    
}

void Partie::pause()
{
    play=false;
}

void Partie::reprendre()
{
    play=true;
}

void Partie::recommencer()
{
    play=true;
    fin=FinPartie::NOP;
    points=0;
    serpent->tailleCorps=1;
    serpent->corps[0]->i=serpent->i;
    serpent->corps[0]->j=serpent->j;
    serpent->corps[0]->orientation=Direction::EST;
    serpent->placerQueue();
    rendu::Rendu::instance().update();
    rendu::Rendu::instance().nom2.clear();
    
    
}

FinPartie Partie::isFin()
{
    return fin;
}

void Partie::sauvegarderScore(std::string nom)
{
    
    std::ifstream ifichierScore;
    std::string line;
    std::vector<std::string> tableauScores;
    int indexLine=0;
    int score=50000;
    int nivo = 4;
    
    tableauScores.reserve(31);
    tableauScores.clear();
    ifichierScore.open("ressources/score.txt");
    
    if(!ifichierScore.is_open()){std::cout<<"impossible d'ouvrir le fichier pour sauvegarder le score"<<std::endl;return;}
    else 
    {
        while(std::getline(ifichierScore, line))
        {
            int i=0;
            while (line[i]!='\0')
            {	if(line[i]!=' ' && line[i]!='\n')
                    {
                            line[i]+=5;
                    }
                    i++;
            }
            if(line.size()!=0)
            tableauScores.push_back(line);
        }
    }
    ifichierScore.close();

    indexLine=0;
    while(nivo>niveau)
    {
        int n=tableauScores[indexLine].find(' ');
        nivo = std::atoi(tableauScores[indexLine].substr(0, n).c_str());
        indexLine++;
    }
    
    indexLine--;
    
    nivo = std::atoi(tableauScores[indexLine].substr(0, 1).c_str());
    if(nivo==niveau)
    {
        while(score>points && nivo==niveau && (uint)indexLine!=tableauScores.size())
        {
            int n1 = tableauScores[indexLine].find(' ');
            nivo = std::atoi(tableauScores[indexLine].substr(0, n1).c_str());
            int n2 = tableauScores[indexLine].find(' ', n1+1);
            score=std::atoi(tableauScores[indexLine].substr(n1, n2-n1).c_str());
            indexLine++;

        }
        indexLine--;
    }    
    
    if((uint)indexLine==tableauScores.size()-1 && nivo==niveau && score>points){tableauScores.push_back(std::string(std::to_string(niveau)+' '+std::to_string(points)+' '+nom));}
    else{tableauScores.insert(tableauScores.begin()+indexLine, std::string(std::to_string(niveau)+' '+std::to_string(points)+' '+nom));}
    
    int un=10, deux=10, trois=10;
    
    for(uint i=0; i<tableauScores.size(); i++)
    {
        nivo = std::atoi(tableauScores[i].substr(0, 1).c_str());
        switch(nivo)
        {
            case 1 : {if(un>0){un--;}else{tableauScores.erase(tableauScores.begin()+i);i--;}} break;
            case 2 : {if(deux>0){deux--;}else{tableauScores.erase(tableauScores.begin()+i);i--;}}break;
            case 3 : {if(trois>0){trois--;}else{tableauScores.erase(tableauScores.begin()+i);i--;}}break;
            default : break;
        }
    }

    
    std::ofstream ofichierScore;
    ofichierScore.open("ressources/score.txt");
    
    if(!ofichierScore.is_open()){std::cout<<"impossible d'ouvrir le fichier pour sauvegarder le score"<<std::endl;return;}
    else 
    {

        ofichierScore.seekp(0, std::ios::beg);
        
        for(uint i=0; i<tableauScores.size(); i++)
        {
            std::string ligne=tableauScores[i];
            crypterLigne(ligne);
            
            ofichierScore<<ligne<<'\n';
        }
    }
    ofichierScore.close();
}

void Partie::crypterLigne(std::string &ligne)
{
    int i=0;
	while (ligne[i]!='\0')
	{	if(ligne[i]!=' ')
		{
			ligne[i]-=5;
		}
		i++;
	}
}

}