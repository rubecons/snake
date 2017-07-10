#ifndef ETATS__TERRAIN__H
#define ETATS__TERRAIN__H


namespace etats {
  class Element;
}

#include "Direction.h"
#include "TerrainType.h"
#include "MurType.h"
#include "Element.h"

namespace etats {

class Terrain : public etats::Element {

public :
  etats::MurType murType;
  etats::TerrainType terrainType;

public:
  Terrain ();
  ~Terrain ();
  Terrain (int i, int j, Direction orientation, TerrainType terrainT, MurType murT);
};

};

#endif
