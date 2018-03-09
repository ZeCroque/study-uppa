#ifndef stock_h
#define stock_h

#define TAILLE 10

#include "produit.h"

class Stock
{
  private :
    Produit _tab[TAILLE];
    int _iMax;
  public :
    Stock();
    Stock(const Stock& s);
    ~Stock();
    Stock& operator = (const Stock& s);
    void ajouterProduit(Produit& p);
    void afficherProduits();
};

#endif
