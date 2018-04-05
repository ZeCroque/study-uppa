#include <iostream>

using namespace std;

template<class Type> int somme(Type* tab, int n)
{
  Type s=tab[0];
  for(int i=1; i<n; i++)
  {
    s+=tab[i];
  }
  return s;
}

int main()
{
  int* tab=new int[10];
  for(int i=0; i<10; i++)
  {
    tab[i]=i;

  }
  cout<<somme(tab, 10)<<endl;
  return 0;
}
