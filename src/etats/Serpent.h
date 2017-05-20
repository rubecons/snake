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

  /// class Serpent - 
  class Serpent : public etats::Element {
    // Associations
    // Attributes
  public:
    std::vector<ElementCorps *> corps;
    int vitesse;
    Partie* partie;
    // Operations
  public:
    Serpent ();
    Serpent (int i, int j, Direction orientation, int vitesse, Partie* part);
    ~Serpent ();
    void avancer ();
    void tourner (Direction dir);
    bool isSerpent(int i, int j, bool serpentSansTete);
    void grandir();
    void placerQueue();
  };

};

#endif
