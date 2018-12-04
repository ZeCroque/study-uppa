#include <iostream>
#include <vector>
#include <fstream>

class Graphe
{
  private:
    int _nbSommet;
    std::vector<std::vector<bool>> _matrixLiens;
  public:
    Graphe();
    Graphe(int nbSommet);
    void ajouterLien(int s1, int s2);
    void afficherGraphe();
    friend std::ostream& operator << (std::ostream& os, const Graphe& g);
};
