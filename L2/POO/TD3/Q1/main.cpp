#include <iostream>
#include "employe.h"

using namespace std;

int main()
{
  Employe e;
  e.saisir("Adrien", "DeLaNoix");
  cout<<e.getNom()<<endl;

  Employe e2("Pierre","Lafitte");
  cout<<e2.getNom()<<endl;


  Employe e3("Jacques", "Henri", "Plombier", 1514);


  e3.travailler();

  cout<<(e3==e3)<<endl;
  cout<<(e2==e3)<<endl;

  cout<<(e3!=e3)<<endl;
  cout<<(e2!=e3)<<endl;

  return 0;
}
