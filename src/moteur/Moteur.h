/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Moteur.h
 * Author: ruben
 *
 * Created on 19 mai 2017, 00:48
 */

#ifndef MOTEUR_H
#define MOTEUR_H

namespace etats{
    class Partie;
}

#include "Commande.h"
#include <list>
#include <mutex>
#include "etats/Partie.h"
//#include "SFML/System/"

namespace moteur
{
class Moteur {
public:
    Moteur();
    void init(etats::Partie* part);
    Moteur(const Moteur& orig);
    Moteur* instance();
    virtual ~Moteur();
    void ajouterCommande(Commande* com);
    void execCommande();
    etats::Partie* partie;
    bool moteurEnabled;
    
private:
    std::list<Commande*> mesCommandes;
    std::mutex mutexMoteur;
    static Moteur* pMoteur;
    
};
}
#endif /* MOTEUR_H */

