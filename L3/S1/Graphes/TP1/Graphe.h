#include <iostream>
#include <vector>
#include "Lien.h"

class Graphe
  {
    private:
      int _nbSommet;
      std::vector<Lien> _vectLiens;
    public:
      Graphe();
      Graphe(int nbSommet, std::vector<Lien> vectLiens);
      void ajouterLien(Lien l);
};
