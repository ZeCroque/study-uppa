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
    void trouverComposanteFortementConnexe();
    std::vector<int> parcoursHistorique();
    Graphe grapheAdjacent();
    std::vector<Graphe> parcoursProfondeur(Graphe adj);

    friend std::ostream& operator << (std::ostream& os, const Graphe& g);
};

void triBulle(std::vector<int>& tab);
