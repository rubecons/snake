#ifndef ETATS__PARTIE__H
#define ETATS__PARTIE__H

#include <vector>
#include <array>
namespace etats {
  class Serpent;
  class ElementFactory;
  class Terrain;
  class Element;
}

namespace moteur {
    class Moteur;
}

namespace rendu {
    class Rendu;
}

#include "Terrain.h"
#include "Element.h"
#include "ElementFactory.h"
#include "Direction.h"
#include "moteur/Moteur.h"
#include "rendu/Rendu.h"

namespace etats {

   
    enum FinPartie{
        GAMEOVER=0,
        VICTOIRE=1
    };
  /// class Partie - 
  class Partie {
    // Associations
    // Attributes
  public:
    Serpent * serpent;
    ElementFactory * factory;
    moteur::Moteur* moteur;
    rendu::Rendu* rendu;
    int points;
    int duree;
    int niveau;
    std::vector<Terrain *> terrain;
    int hauteur;
    int largeur;
    unsigned int indexTerrain;
    std::array<int,2> fruit;
    bool play;
    
    // Operations
  public:
    Partie ();
    ~Partie ();
    void nouvellePartie (int niv);
    int getPoints ();
    float getDuree ();
    int getNiveau ();
    void setPoints (int points);
    void placerFruit();
    void finPartie(FinPartie fin);
    void pause();
    void reprendre();
  };

};

#endif
