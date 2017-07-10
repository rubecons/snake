/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Moteur.cpp
 * Author: ruben
 * 
 * Created on 19 mai 2017, 00:48
 */

#include <thread>
#include <iostream>
#include "Moteur.h"
namespace moteur
{

Moteur::Moteur() {
}

Moteur& Moteur::instance() {
    static Moteur moteur;
    return moteur;
}


void Moteur::init()
{
    mesCommandes.clear();
}

Moteur::Moteur(const Moteur& orig) {
}

Moteur::~Moteur() {
}

void Moteur::clearCommandes()
{
    mesCommandes.clear();
}

void Moteur::ajouterCommande(Commande* com)
{
    if(etats::Partie::instance().play)
    {
        mutexMoteur.lock();
        mesCommandes.push_back(com);
        mutexMoteur.unlock();
    }
}

void Moteur::execCommande()
{

    if(etats::Partie::instance().play==true){
        if(mesCommandes.empty()==false)
        {
            mutexMoteur.lock();
            mesCommandes.front()->effectuerCommande();
            mesCommandes.pop_front();
            mutexMoteur.unlock();
        }
    }
}

void Moteur::threadCaller()
{
    std::thread threadMoteur(&Moteur::execCommande, this);
    threadMoteur.detach();
}

}