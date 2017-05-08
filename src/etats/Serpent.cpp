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
{
    this->vitesse=vitesse;
    //std::cout<<"serpent"<<i<<"  "<<j<<"  orientation"<< orientation<<"  vitesse "<<vitesse<<std::endl;
}

Serpent::~Serpent ()
{}

void Serpent::avancer ()
{}

void Serpent::tourner ()
{}

    
}