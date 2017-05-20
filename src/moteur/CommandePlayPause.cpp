/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CommandePlayPause.cpp
 * Author: ruben
 * 
 * Created on 19 mai 2017, 19:04
 */

#include "CommandePlayPause.h"
#include "etats/Partie.h"

namespace moteur
{
CommandePlayPause::CommandePlayPause(etats::Partie* part) {
    partie=part;
    moteur=part->moteur;
}

CommandePlayPause::CommandePlayPause(const CommandePlayPause& orig) {
}

CommandePlayPause::~CommandePlayPause() {
}

void CommandePlayPause::effectuerCommande()
{
    partie->play=!partie->play;
    moteur->moteurEnabled=!moteur->moteurEnabled;
}


}