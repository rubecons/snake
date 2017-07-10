
#ifndef RENDU__RENDU__H
#define RENDU__RENDU__H

//#include "Couche.h"
#include <vector>
//#include <SFML/Graphics.hpp>
#include "etats/Partie.h"
#include "TileMap.h"
#include "PageAccueil.h"

namespace etats {
  class Partie;
};


namespace rendu {
 
class Rendu {

public:
  sf::RenderWindow *wind;
  sf::View vue;
  rendu::TileMap map;
  unsigned int winX, winY;
  int H, L, tailleCote;
  bool accueil;
  std::string nom2;
  sf::Text meilleursScores;
  rendu::PageAccueil pageAccueil;


public:
  Rendu();
  ~Rendu();
  static Rendu & instance();
  void init ();
  void afficherPageAccueil();
  void update();
  void lancerHorloge();
  void threadCallerHorloge();
  void actualiserScores();
};

};

#endif
