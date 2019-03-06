#include <stdio.h>
#include "vector.h"

int main()
{
	Vector v=vide();
	printf("Le vecteur est-il vide?\n%d\n",estVide(v));
	inserer(&v, 0, 8);
  inserer(&v, 1, 84);
	inserer(&v, 2, 78);
	printf("Vecteur après initialisation :\n%d\n%d\n%d\nTaille du vecteur : %d\n",ieme(v,0),ieme(v,1),ieme(v,2),(taille(v)));
	supprimer(&v, 1);
	supprimer(&v, 1);
	inserer(&v, 1, 42);
	modifier(v, 0,14);
	printf("Vecteur après modification :\n%d\n%d\nTaille du vecteur : %d\n",ieme(v,0),ieme(v,1),(taille(v)));

}
