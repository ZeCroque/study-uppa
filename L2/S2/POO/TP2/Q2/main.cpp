#include <iostream>
#include "stock.h"

using namespace std;

int main()
{
  Produit p;
  p.setNom("Tomate");
  p.setCode(18);
  cout<<p;

  Produit tab[5];

  for (int i=0; i<5; i++)
  {
    tab[i]=p;
    cout<<tab[i];
  }

  Produit* tab2 = new Produit[5];

  for (int i=0; i<5; i++)
  {
    tab2[i]=p;
    cout<<tab2[i];
  }

  delete[] tab2;

  Stock s;
  s.ajouterProduit(p);
  s.ajouterProduit(p);
  s.afficherProduits();

  Stock s2;
  s2=s;
  s2.afficherProduits();

  return 0;
}
