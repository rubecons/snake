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

namespace moteur
{
class Moteur {
public:
    Moteur();
    static Moteur & instance();
    void init();
    Moteur(const Moteur& orig);
    virtual ~Moteur();
    void ajouterCommande(Commande* com);
    void execCommande();
    void threadCaller();
    void clearCommandes();
    std::list<Commande*> mesCommandes;
private:
    
    std::mutex mutexMoteur;
    
};
}
#endif /* MOTEUR_H */

