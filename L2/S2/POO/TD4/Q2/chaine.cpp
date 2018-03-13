#include "chaine.h"
#include <iostream>
#include <string.h>

Chaine::Chaine()
{
  this->_tab=new char*;
  *(this->_tab)=new char[DEFAULT_SIZE];
  this->_size=DEFAULT_SIZE;
  this->_length=0;
}

Chaine::Chaine(const Chaine& c)
{
  this->_tab=new char*;
  this->_size=c._size;
  this->_length=c._length;
  *(this->_tab)=*(c._tab);
}

Chaine::~Chaine()
{

}

Chaine& Chaine::operator = (const Chaine& c)
{
  delete[] *(this->_tab);
  this->_size=c._size;
  *(this->_tab)=*(c._tab);
  this->_length=c._length;
  return (*this);
}

void Chaine::setText(char* c)
{
  delete[] *(this->_tab);
  this->_size=strlen(c);
  this->_length=this->_size;
  *(this->_tab)=c;
}

char* Chaine::getText()
{
  return *(this->_tab);
}

void Chaine::affiche()
{
  std::cout<<*(this->_tab)<<std::endl;
}
