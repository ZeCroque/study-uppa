#include "exemplaire.h"

Exemplaire::Exemplaire()
{
  this->_reference=0;
}

Exemplaire::Exemplaire(int ref)
{
  this->_reference=ref;
}

Exemplaire::~Exemplaire()
{

}

bool Exemplaire::operator == (const Exemplaire& e)
{
  return this->_reference==e._reference;
}

int Exemplaire::getRef()
{
  return this->_reference;
}
