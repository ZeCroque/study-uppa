#ifndef ensemble__h
#define ensemble__h


#include <vector>
#include <iostream>

template<class Type> class Ensemble
{
  private :
    std::vector<Type> elements;

  public :
    Ensemble();
    Ensemble(const Ensemble<Type>& e);
    ~Ensemble();
    Ensemble<Type>& operator = (const Ensemble<Type>& e);
    bool appartient(Type e);
    int card();
    void inserer(Type e);
    void affiche();
    void affiche(int rang);
    void retirer(const Ensemble e);

};

template <class Type> Ensemble<Type>::Ensemble()
{

}

template <class Type> Ensemble<Type>::Ensemble(const Ensemble<Type>& e)
{
  (*this)=e;
}

template <class Type> Ensemble<Type>::~Ensemble()
{

}

template <class Type> Ensemble<Type>& Ensemble<Type>::operator = (const Ensemble<Type>& e)
{
  this->elements=e.elements;
  return (*this);
}

template <class Type> bool Ensemble<Type>::appartient(Type e)
{
  typename std::vector<Type>::iterator it;
  for(it = this->elements.begin(); it!=this->elements.end(); it++)
  {
    if((*it)==e)
    {
      return true;
    }
  }
  return false;
}

template <class Type> int Ensemble<Type>::card()
{
  return this->elements.size();
}

template <class Type> void Ensemble<Type>::inserer(Type e)
{
  if(!appartient(e))
  {
    this->elements.push_back(e);
  }
  else
  {
    std::cout<<"Elément déjà présent"<<std::endl;
  }
}

template <class Type> void Ensemble<Type>::affiche()
{
  typename std::vector<Type>::iterator it;
  for(it = this->elements.begin(); it!=this->elements.end(); it++)
  {
    std::cout<<(*it)<<std::endl;
  }
}

template <class Type> void Ensemble<Type>::affiche(int rang)
{
  std::cout<<this->elements[rang]<<std::endl;
}

template <class Type> void Ensemble<Type>::retirer(Ensemble e)
{
  typename std::vector<Type>::iterator it;
  typename std::vector<Type>::iterator it2;

  for(it = e.elements.begin(); it!=e.elements.end(); it++)
  {

    for(it2 = this->elements.begin(); it2!=this->elements.end(); it2++)
    {
      if(*it2==*it)
      {
        this->elements.erase(it2);
        break;
      }
    }
  }
}

#endif
