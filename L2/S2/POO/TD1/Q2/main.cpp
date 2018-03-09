#include "helloworld.h"

int main()
{
  HelloWorld* h=new HelloWorld();
  h->hello();
  delete h;
}
