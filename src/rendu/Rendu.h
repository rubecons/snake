
#ifndef RENDU__RENDU__H
#define RENDU__RENDU__H

//#include "Couche.h"
#include <vector>
#include <SFML/Graphics.hpp>



namespace etats {
  class Partie;
}

namespace rendu
{
    class TileMap;
}


#include "etats/Partie.h"
#include "TileMap.h"


namespace rendu {

  /// class Rendu - 
  class Rendu {
    // Attributes
  public:
    sf::RenderWindow *wind;
    etats::Partie * partie;
    moteur::Moteur * moteur;
    //std::vector<Couche> couchesTerrain;
    TileMap *map;
    unsigned int winX, winY;
    int H, L, tailleCote;
    
    // Operations
  public:
    Rendu();
    ~Rendu();
    void init (etats::Partie* part);
    void update();
  };

};

#endif
