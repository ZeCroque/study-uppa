#include <stdio.h>
#include <stdlib.h>

typedef int Elt;

typedef struct cellule
{
	Elt elem;
	int pos;
	struct cellule* suivant;
} Cellule;

typedef Cellule* Vector;

int taille(Vector v);
Vector vide();
void inserer(Vector* v, int pos, Elt element);
Vector modifier(Vector v, int pos, Elt element);
Vector supprimer(Vector* v, int pos);
Elt ieme(Vector v, int pos);
int estVide(Vector v);
