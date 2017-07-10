#ifndef ETATS__ELEMENT__H
#define ETATS__ELEMENT__H


#include "Direction.h"

namespace etats {

 
class Element {

public:
  int i;
  int j;
  Direction orientation;
  // Operations
public:
  Element ();
  Element (int i, int j, Direction orientation);
  ~Element ();
};

};

#endif
