/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CommandeAvancer.cpp
 * Author: ruben
 * 
 * Created on 19 mai 2017, 02:25
 */

#include "CommandeAvancer.h"
#include "etats/Direction.h"
#include "etats/Partie.h"
#include "etats/Serpent.h"
namespace moteur
{
CommandeAvancer::CommandeAvancer() {
}

CommandeAvancer::CommandeAvancer(etats::Partie* part)
{
    partie=part;
    
}

CommandeAvancer::CommandeAvancer(const CommandeAvancer& orig) {
}

CommandeAvancer::~CommandeAvancer() {
}

void CommandeAvancer::effectuerCommande()
{
    partie->serpent->avancer();
    partie->rendu->update();
}

}