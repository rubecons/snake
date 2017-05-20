
#ifndef ETATS__ELEMENTFACTORY__H
#define ETATS__ELEMENTFACTORY__H

#include <stdlib.h>

namespace etats {
  class Terrain;
  class Element;
}

#include "Terrain.h"
#include "Element.h"

namespace etats {

  /// class ElementFactory - 
  class ElementFactory {
    // Associations
    // Operations
  public:
    ElementFactory ();
    ~ElementFactory ();
    Terrain * const newInstance (char c, size_t i, size_t j);
  };

};

#endif
