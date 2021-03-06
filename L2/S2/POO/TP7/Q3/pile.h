#ifndef pile__h
#define pile__h

#include <iostream>
#include <vector>

template<class Type> class Pile
{
  private:
    std::vector<Type> elem;

  public:
    Pile();
    Pile(const Pile& p);
    ~Pile();
    Pile& operator = (const Pile& p);
    void operator << (const Type& t);
    void operator >> (Type& t);
    Type top();
    template <class T> friend std::ostream& operator << (std::ostream& os, const Pile<T>& p);

};


template <class Type> Pile<Type>::Pile()
{

}

template <class Type> Pile<Type>::Pile(const Pile& p)
{
  *this=p;
}

template <class Type> Pile<Type>::~Pile()
{

}

template<class Type> Type Pile<Type>::top()
{
  return this->elem[this->elem.size()-1];
}

template <class Type> Pile<Type>& Pile<Type>::operator = (const Pile& p)
{
  this->elem=p.elem;
  return *this;
}

template <class Type> void Pile<Type>::operator << (const Type& t)
{
  this->elem.push_back(t);
}

template <class Type> void Pile<Type>::operator >> (Type& t)
{
  t=this->elem[this->elem.size()-1];
  this->elem.pop_back();
}


template <class Type> std::ostream& operator << (std::ostream& os, const Pile<Type>& p)
{
  for(int i = 0; i<p.elem.size(); i++)
  {
    os<<p.elem[i]<<std::endl;
  }
  return os;
}


#endif
