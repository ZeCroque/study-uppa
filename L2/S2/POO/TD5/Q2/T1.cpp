#include "T1.h"

T1::T1()
{
  this->afficher();
}

T1::~T1()
{
  std::cout<<"On détruit T1"<<std::endl;
  this->afficher();
}

void T1::afficher()
{
  std::cout<<"Classe T1"<<std::endl;
}
