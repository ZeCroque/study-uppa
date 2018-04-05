#include <iostream>

using namespace std;

template<class Type> int carre(Type t)
{
  return t*t;
}

int main()
{
  cout<<carre(2)<<endl;
  return 0;
}
