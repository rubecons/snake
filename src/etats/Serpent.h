#ifndef ETATS__SERPENT__H
#define ETATS__SERPENT__H

#include <vector>

namespace etats {
  class Partie;
  class ElementCorps;
  class Element;
}

#include "Direction.h"
#include "Element.h"
#include "ElementCorps.h"
#include "Partie.h"

namespace etats {

 
class Serpent : public etats::Element {

public:
  std::vector<ElementCorps *> corps;
  int vitesse;

  int tailleCorps;
  int i, j;

public:
  Serpent ();
  Serpent (int i, int j, Direction orientation, int vitesse);
  ~Serpent ();
  void avancer ();
  void tourner (Direction dir);
  bool isSerpent(int i, int j, bool serpentSansTete);
  void grandir();
  void placerQueue();
};

};

#endif
