#include <iostream>
#include "T1.h"
#include "T2.h"

using namespace std;

int main()
{
  T1* pt=new T2();
  delete pt;

  return 0;
}
