#include "oeuvres.h"
#include <iostream>

using namespace std;

Oeuvres::Oeuvres()
{}

Oeuvres::Oeuvres(Oeuvres& a)
{
  (*this)=a;
}

Oeuvres::~Oeuvres() {}

Oeuvres& Oeuvres::operator = (const Oeuvres& a)
{
  this->_oeuvreTab=a._oeuvreTab;
  this->_size=a._size;
  return (*this);
}

void Oeuvres::addOeuvre(Oeuvre& a)
{
  this->_oeuvreTab.push_back(a);
}

void Oeuvres::removeOeuvre(int index)
{
  vector<Oeuvre>::iterator it;
  int i=0;

  for(it = this->_oeuvreTab.begin(), i=0; it!=this->_oeuvreTab.end() && i<=index; ++it, i++)
  {
    this->_oeuvreTab.erase(it);
  }
}

void Oeuvres::afficheOeuvre(int index)
{
  if (index<(int)this->_oeuvreTab.size())
  {
    cout<<this->_oeuvreTab[index]<<endl;
  }
  else
  {
    cout<<"Hors tableau"<<endl;
  }

}
