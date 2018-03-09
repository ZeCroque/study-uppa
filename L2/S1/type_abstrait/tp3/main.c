#include <stdio.h>
#include "set.h"

int main()
{
  Set s;
  s=vide();

  ajouter(&s,12);
  ajouter(&s,12);
  ajouter(&s, 10);
  printf("%d\n", appartient(s,12));
  printf("%d\n", appartient(s,10));
  printf("%d\n", appartient(s,7));
  enlever(&s, 12);
  printf("%d\n", appartient(s,12));
  enlever(&s, 10);
  printf("%d\n", appartient(s,10));

  printf("%d\n",estVide(s));

  return 0;
}
