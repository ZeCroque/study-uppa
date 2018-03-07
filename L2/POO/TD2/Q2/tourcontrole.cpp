#include "tourcontrole.h"

using namespace std;

TourDeControle::TourDeControle()
{
  for(int i=0; i<TAILLE; i++)
  {
    this->tab[i]=Avion();
    this->indexMax=0;
  }
}

TourDeControle::TourDeControle(const TourDeControle& a)
{
  (*this)=a;
}

TourDeControle::~TourDeControle()
{

}

TourDeControle& TourDeControle::operator = (const TourDeControle& a)
{
  for(int i=0; i<TAILLE; i++)
  {
    this->tab[i]=a.tab[i];
  }
  this->indexMax=a.indexMax;
  return (*this);
}

int TourDeControle::getIndexMax() const
{
  return this->indexMax;
}

Avion TourDeControle::getAvionAt(int index) const
{
  if(index<indexMax && index<TAILLE)
  {
      return this->tab[index];
  }
  cout<<"L'index est supérieur à la taille du tableau ou correspond à une case vide.\nL'avion renvoyé est vide."<<endl;
  Avion a;
  return a;

}

  void TourDeControle::ajouterTabAvionNormal(const Avion& a)
  {

    if (indexMax<TAILLE)
    {
      tab[indexMax].setFabriquant(a.getFabriquant());
      tab[indexMax].setType(a.getType());
      tab[indexMax].setAltitude(a.getAltitude());
      tab[indexMax].setCap(a.getCap());
      indexMax++;
    }
    else
    {
      cout<<"Vous ne pouvez rentrer plus de 5 avions."<<endl;
    }

  }

  void TourDeControle::ajouterAvionAmie(const Avion& a)
  {
    if (indexMax<TAILLE)
    {
      tab[indexMax]._fabriquant=a._fabriquant;
      tab[indexMax]._type=a._type;
      tab[indexMax]._altitude=a._altitude;
      tab[indexMax]._cap=a._cap;
      indexMax++;
    }
    else
    {
      cout<<"Vous ne pouvez rentrer plus de 5 avions."<<endl;
    }
  }

  void TourDeControle::ajouterAvion(const Avion &a)
  {
    if (indexMax<TAILLE)
    {
      tab[indexMax]=a;
      indexMax++;
    }
    else
    {
      cout<<"Vous ne pouvez rentrer plus de 5 avions."<<endl;
    }
  }
