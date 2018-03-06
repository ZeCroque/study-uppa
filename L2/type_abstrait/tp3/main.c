#include <stdio.h>
#include "set.h"

int main()
{
  Set s;

  //On créer un set vide
  s=vide();

  system("clear");
  printf("On ajoute 12, 12(qui ne sera pas pris en compte), 10 puis 11 dans le set");
  //On ajoute 12 dans le set
  ajouter(&s,12);
  //On essaye de nouveau, mais la fonction gère le cas
  ajouter(&s,12);
  //On ajoute 10 dans le set
  ajouter(&s, 10);
  //On ajoute 11 dans le set
  ajouter(&s, 11);

  //On teste la présence d'éléments
  printf("\n\n12 appartient-il au set? %d\n", appartient(s,12));
  printf("10 appartient-il au set? %d\n", appartient(s,10));
  printf("7 appartient-il au set? %d\n", appartient(s,7));

  //On enlève les élements en testant que cela a fonctionné
  enlever(&s, 12);
  printf("\nElement supprimés.\n\n12 appartient-il au set? %d\n", appartient(s,12));
  enlever(&s, 10);
  printf("10 appartient-il au set? %d\n", appartient(s,10));
  enlever(&s, 11);
  printf("11 appartient-il au set? %d\n", appartient(s,11));

  printf("\nLe set est-il vide? %d\n\n",estVide(s));

  return 0;
}
