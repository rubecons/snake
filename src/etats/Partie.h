#ifndef ETATS__PARTIE__H
#define ETATS__PARTIE__H

#include <vector>
#include <array>
namespace etats {
  class Serpent;
  class ElementFactory;
  class Terrain;
  class Element;
}

namespace moteur {
    class Moteur;
}

namespace rendu {
    class Rendu;
}
#include "Serpent.h"
#include "Terrain.h"
#include "Element.h"
#include "ElementFactory.h"
#include "Direction.h"
#include "moteur/Moteur.h"
#include "rendu/Rendu.h"

namespace etats {

   
    enum FinPartie{
        NOP=-1,
        GAMEOVER=0,
        VICTOIRE=1
    };
 
class Partie {

public:
  Serpent * serpent;
  ElementFactory * factory;

  int points;
  int duree;
  int niveau;
  std::vector<Terrain *> terrain;
  int hauteur;
  int largeur;
  unsigned int indexTerrain;
  std::array<int,2> fruit;
  bool play;
  FinPartie fin;

public:
  Partie ();
  ~Partie ();
  static Partie & instance();
  void nouvellePartie (int niv);
  void quitterPartie();
  std::string lectureFichierNiveau(int niveau);
  int getPoints ();
  float getDuree ();
  int getNiveau ();
  void setPoints (int points);
  void placerFruit();
  void finPartie(FinPartie fin);
  void pause();
  void reprendre();
  void recommencer();
  FinPartie isFin();
  void sauvegarderScore(std::string nom);
  void crypterLigne(std::string &ligne);
};

};

#endif
