#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

class Graphe
{
  private:
    int _nbSommet;
    std::vector<std::vector<bool> > _matrixLiens;
  public:
    Graphe();
    Graphe(int nbSommet);
    void ajouterLien(int s1, int s2);
    void afficherGraphe();
    std::vector<std::vector<int> > getStables();
    friend std::ostream& operator << (std::ostream& os, const Graphe& g);
};

bool contains(std::vector<int> tab, int e);
