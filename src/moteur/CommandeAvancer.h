/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CommandeAvancer.h
 * Author: ruben
 *
 * Created on 19 mai 2017, 02:25
 */

#ifndef COMMANDEAVANCER_H
#define COMMANDEAVANCER_H

namespace etats{
    class Partie;
}





#include "etats/Partie.h"
#include "Commande.h"


namespace moteur
{
    

class CommandeAvancer : public Commande {
public:
    CommandeAvancer();
    CommandeAvancer(etats::Partie* part);
    CommandeAvancer(const CommandeAvancer& orig);
    virtual ~CommandeAvancer();
    void effectuerCommande();
private:
    etats::Partie* partie;
};
}
#endif /* COMMANDEAVANCER_H */

