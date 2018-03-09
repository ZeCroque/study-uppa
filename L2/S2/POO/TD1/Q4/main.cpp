#include <iostream>
#include "ensemble.h"

using namespace std;

int main()
{
  Ensemble<char> c;
  Ensemble<int> i;

  c.inserer('c');
  cout<<c.appartient('c')<<endl;

  i.inserer(2);
  i.inserer(18);
  i.inserer(65);
  cout<<i.appartient(2)<<endl;
  cout<<i.appartient(4)<<endl;

  Ensemble<int> i2=i;
  cout<<i2.appartient(18)<<endl;
  i2.affiche();
  i2.affiche(2);
  i2.inserer(2);
  cout<<i2.card()<<endl;

  Ensemble<char> c2(c);
  c2.affiche();



  return 0;
}
