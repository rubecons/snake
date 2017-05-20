/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Commande.h
 * Author: ruben
 *
 * Created on 19 mai 2017, 00:50
 */

#ifndef COMMANDE_H
#define COMMANDE_H
namespace moteur
{

class Commande {
public:
    Commande();
    Commande(const Commande& orig);
    virtual ~Commande();
    virtual void effectuerCommande();
private:

};
}
#endif /* COMMANDE_H */

