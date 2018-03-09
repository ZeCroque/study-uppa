#include <iostream>

using namespace std;

#define NMOIS 12

typedef struct
{
  int stock;
  float prix;
  int ventes[NMOIS];
} enreg;

void raz(enreg& e)
{
  int i=0;

  e.stock=0;
  e.prix=0.0;
  for(i=0;i<NMOIS; i++)
  {
    e.ventes[i]=0;
  }
}

void raz(enreg* e)
{
  int i=0;

  e->stock=0;
  e->prix=0.0;
  for(i=0;i<NMOIS; i++)
  {
    e->ventes[i]=0;
  }
}

void afficherEnreg(enreg e)
{
  int i=0;
  cout<<"Stock : "<<e.stock<<"\nPrix : "<<e.prix<<"\nVentes :"<<endl;
  for(i=0;i<NMOIS;i++)
  {
    cout<<e.ventes[i]<<endl;
  }

}

int main()
{
  enreg e;
  enreg e2;

  e.stock=18;
  e.ventes;
  e.prix=44.99;
  afficherEnreg(e);

  e2.stock=74;
  e2.ventes;
  e2.prix=15;
  afficherEnreg(e2);

  raz(e);
  afficherEnreg(e);
  raz(&e2);
  afficherEnreg(e2);

  return 0;
}
