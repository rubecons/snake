/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CommandeTourner.h
 * Author: ruben
 *
 * Created on 19 mai 2017, 02:26
 */

#ifndef COMMANDETOURNER_H
#define COMMANDETOURNER_H

namespace etats{
    class Partie;
}


#include "etats/Direction.h"
#include "Commande.h"
#include "etats/Partie.h"

namespace moteur
{
class CommandeTourner : public Commande {
public:
    CommandeTourner();
    CommandeTourner(etats::Partie* part, etats::Direction dir);
    CommandeTourner(const CommandeTourner& orig);
    virtual ~CommandeTourner();
    void effectuerCommande();
private:
    etats::Direction direction;
    etats::Partie* partie;
};
}
#endif /* COMMANDETOURNER_H */

