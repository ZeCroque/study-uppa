#include "T2.h"

T2::T2()
{
  this->afficher();
}

T2::~T2()
{
  std::cout<<"On détruit T2"<<std::endl;
  this->afficher();
}

void T2::afficher()
{
  std::cout<<"Classe T2"<<std::endl;
}
