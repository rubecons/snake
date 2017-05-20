/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CommandeTourner.cpp
 * Author: ruben
 * 
 * Created on 19 mai 2017, 02:26
 */

#include "CommandeTourner.h"
//#include "etats/Partie.h"
#include "etats/Serpent.h"
//#include "etats/Serpent.h"
namespace moteur
{
CommandeTourner::CommandeTourner() {
}

CommandeTourner::CommandeTourner(etats::Partie* part, etats::Direction dir)
{
    partie=part;
    direction=dir;
}

CommandeTourner::CommandeTourner(const CommandeTourner& orig) {
}

CommandeTourner::~CommandeTourner() {
}

void CommandeTourner::effectuerCommande()
{
    partie->serpent->tourner(direction);
    
}

}