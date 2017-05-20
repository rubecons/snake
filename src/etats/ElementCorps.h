#ifndef ETATS__ELEMENTCORPS__H
#define ETATS__ELEMENTCORPS__H


namespace etats {
  class Element;
}

#include "Direction.h"
#include "Element.h"

namespace etats {

  /// class ElementCorps - 
  class ElementCorps : public etats::Element {
    // Attributes
  public:
    bool visible;
    // Operations
  public:
    ElementCorps ();
    ~ElementCorps ();
    ElementCorps (int i, int j, Direction orientation, bool visi);
  };

};

#endif
