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
    std::vector<std::pair<int,int> > parcoursHistorique();
    Graphe grapheAdjacent();
    std::vector<std::vector <int> > parcoursProfondeur(Graphe adj, std::vector<std::pair<int, int> > datesFin);

    friend std::ostream& operator << (std::ostream& os, const Graphe& g);
};

void triBulle(std::vector<std::pair<int, int> >& tab);
bool contains(std::vector<int> tab, int e);
int getElementIndex(std::vector<std::pair<int, int> > tab, int e);
