#include <iostream>
#include "pile.h"
#include <string>

using namespace std;

int main()
{
  Pile<string> p;
  p<<"pute";
  p<<"Mrissa";
  p<<"Google";
  cout<<p;
  return 0;
}
