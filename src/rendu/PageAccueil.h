/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PageAccueil.h
 * Author: ruben
 *
 * Created on 2 juin 2017, 21:16
 */

#ifndef PAGEACCUEIL_H
#define PAGEACCUEIL_H

#include <SFML/Graphics/Text.hpp>
#include "etats/Partie.h"
#include <array>


namespace rendu
{

class FondAccueil : public sf::Drawable, public sf::Transformable
{
public:
    sf::RenderWindow *fenetre;
    sf::Texture imageAccueil;
    sf::VertexArray quad;
    
    FondAccueil(){}
    ~FondAccueil(){}
    void init();
    //void resizeFond();//sf::Event::SizeEvent size);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
};
    
class PageAccueil
{
public:
    int niveau;
    sf::RenderWindow *fenetre;
    FondAccueil fond;
    int tailleJouer=100;
    int tailleTexteNiv = 40;
    
    std::array<int , 2> curseur;
    
    
public:
    
    PageAccueil();
    PageAccueil(const PageAccueil& orig);
    virtual ~PageAccueil();
    void init();
    void enregisrerNiveauViaCurseur();
private:

};


}
#endif /* PAGEACCUEIL_H */

