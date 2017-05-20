/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CommandePlayPause.h
 * Author: ruben
 *
 * Created on 19 mai 2017, 19:04
 */

#ifndef COMMANDEPLAYPAUSE_H
#define COMMANDEPLAYPAUSE_H

#include "Moteur.h"
#include "Commande.h"

namespace moteur
{
    
class CommandePlayPause : public Commande{
public:
    CommandePlayPause(etats::Partie* part);
    CommandePlayPause(const CommandePlayPause& orig);
    virtual ~CommandePlayPause();
    void effectuerCommande();

private:
    etats::Partie* partie;
    Moteur* moteur;
};

}
#endif /* COMMANDEPLAYPAUSE_H */

