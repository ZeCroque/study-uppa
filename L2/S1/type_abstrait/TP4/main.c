#include "arbre.h"

int main()
{
  Arbre A;
  construireArbre(&A);
  printf("%d\n", estArbreVide(A));
  insererEltArbre(&A, 2);
  printf("%d\n", racine(A));
  printf("%d\n", estArbreVide(A));
  insererEltArbre(&A, 4);
  printf("%d\n", racine(fils(A,0)));
  insererEltArbre(&A, 17);
  printf("%d\n", racine(fils(A,1)));
  insererEltArbre(&A, 82);
  printf("%d\n", racine(fils(A,2)));
  printf("%d\n", nombreSousArbre(A));



  return 0;
}
