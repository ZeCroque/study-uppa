#include "avion.h"

using namespace std;

Avion::Avion()
{
  this->_fabriquant="";
  this->_type=0;
  this->_altitude=0.0;
  this->_cap=0.0;
}

Avion::Avion(const Avion& a)
{
  (*this)=a;
}

Avion::~Avion()
{

}

Avion& Avion::operator = (const Avion& a)
{
  this->_fabriquant=a._fabriquant;
  this->_type=a._type;
  this->_altitude=a._altitude;
  this->_cap=a._cap;
  return (*this);
}

void Avion::setFabriquant(string fabriquant)
{
  this->_fabriquant=fabriquant;
}

void Avion::setType(int type)
{
  this->_type=type;
}

void Avion::setAltitude(float alt)
{
  this->_altitude=alt;
}

void Avion::setCap(float cap)
{
  this->_cap=cap;
}

string Avion::getFabriquant() const
{
  return this->_fabriquant;
}

int Avion::getType() const
{
  return this->_type;
}

float Avion::getCap() const
{
  return this->_cap;
}

float Avion::getAltitude() const
{
    return this->_altitude;
}


void afficheFiche(const Avion& a)
{
  cout<<"Fabriquant : "<<a._fabriquant<<"\nType : "<<a._type<<"\nAltitude : "<<a._altitude<<"\nCap : "<<a._cap<<endl;
}

std::ostream & operator << (std::ostream& os, const Avion& a)
{
  os<<"Fabriquant : "<<a.getFabriquant()<<"\nType : "<<a.getType()<<"\nAltitude : "<<a.getAltitude()<<"\nCap : "<<a.getCap()<<endl;
  return os;
}
