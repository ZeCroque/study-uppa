#include "adherents.h"
#include <iostream>

using namespace std;

Adherents::Adherents()
{}

Adherents::Adherents(Adherents& a)
{
  (*this)=a;
}

Adherents::~Adherents() {}

Adherents& Adherents::operator = (const Adherents& a)
{
  this->_adherentTab=a._adherentTab;
  this->_size=a._size;
  return (*this);
}

void Adherents::addAdherent(Adherent& a)
{
  this->_adherentTab.push_back(a);
}

void Adherents::removeAdherent(int index)
{
  vector<Adherent>::iterator it;
  int i=0;

  for(it = this->_adherentTab.begin(), i=0; it!=this->_adherentTab.end() && i<=index; ++it, i++)
  {
    this->_adherentTab.erase(it);
  }
}

void Adherents::afficheAdherent(int index)
{
  if (index<(int)this->_adherentTab.size())
  {
    cout<<this->_adherentTab[index]<<endl;
  }
  else
  {
    cout<<"Hors tableau"<<endl;
  }

}
