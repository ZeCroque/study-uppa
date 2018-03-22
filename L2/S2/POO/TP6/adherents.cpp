#include "adherents.h"
#include <iostream>

using namespace std;

Adherents::Adherents() {}

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

void Adherents::addAdherent(Adherent* a)
{
  this->_adherentTab.push_back();
  //TODO
}

void Adherents::removeAdherent(Adherent* a)
{

}
