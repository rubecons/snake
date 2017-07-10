#ifndef ETATS__ELEMENTCORPS__H
#define ETATS__ELEMENTCORPS__H


namespace etats {
  class Element;
}

#include "Direction.h"
#include "Element.h"

namespace etats {


class ElementCorps : public etats::Element {

public:
  bool visible;

public:
  ElementCorps ();
  ~ElementCorps ();
  ElementCorps (int i, int j, Direction orientation, bool visi);
};

};

#endif
