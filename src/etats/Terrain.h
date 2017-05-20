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

  /// class Terrain - 
  class Terrain : public etats::Element {
    // Associations
  public :
    etats::MurType murType;
    etats::TerrainType terrainType;
    // Operations
  public:
    Terrain ();
    ~Terrain ();
    Terrain (int i, int j, Direction orientation, TerrainType terrainT, MurType murT);
  };

};

#endif
