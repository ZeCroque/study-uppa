#include <iostream>
#include "produit.h"

using namespace std;

int main()
{
  Produit p;
  p.setNom("Jean");
  p.setCode(18);
  cout<<p;

  return 0;
}
