#include <iostream>
#include "deck.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
  //Initialise l'aléatoire
  srand (time(NULL));

  ///////DEBUG///////

  Deck d;
  Carte c;

  cout<<d<<endl<<endl;
  c=d.draw();
  cout<<d;
  
  return 0;
}
