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

#include "Moteur.h"
namespace moteur
{
    Moteur* Moteur::pMoteur=nullptr;

Moteur::Moteur() {
}

void Moteur::init(etats::Partie* part)
{
    partie=part;
    moteurEnabled=true;
}

Moteur::Moteur(const Moteur& orig) {
}

Moteur* Moteur::instance()
{
    if( !pMoteur) pMoteur=new Moteur;
    return pMoteur;
}

Moteur::~Moteur() {
}

void Moteur::ajouterCommande(Commande* com)
{
    if(moteurEnabled)
    {
        mutexMoteur.lock();
        mesCommandes.push_back(com);
        mutexMoteur.unlock();
    }
}

void Moteur::execCommande()
{
    while(1)
    {
        if(moteurEnabled){
        while(!mesCommandes.empty())
        {
            mutexMoteur.lock();
            mesCommandes.front()->effectuerCommande();
            mesCommandes.pop_front();
            mutexMoteur.unlock();
        }}
    }
}

}