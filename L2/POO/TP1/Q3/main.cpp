#include <iostream>

using namespace std;

//Passage par valeur, puis échange --> Inutile
void echange1(int a, int b)
{
  int aux=0;

  aux=a;
  a=b;
  b=aux;
}

//Passage par réference, puis échange
void echange(int& a, int& b)
{

  int aux=0;

  aux=a;
  a=b;
  b=aux;
}

//Passage par pointeur, puis échange
void echange(int* a, int* b)
{
  int aux=0;

  aux=*a;
  *a=*b;
  *b=aux;
}

int main()
{
  int a=4;
  int b=7;

  echange1(8,4);
  echange(a,b);
  cout<<"a : "<<a<<" b : "<<b<<endl;
  echange(&a,&b);
  cout<<"a : "<<a<<" b : "<<b<<endl;
  return 0;
}
