#include <stdio.h>
#include <stdlib.h>

typedef int Elt;

typedef struct cellule
{
	Elt elem;
	struct cellule* suiv;
} Cellule;

typedef Cellule* Set;

Set vide();
void ajouter(Set* s, Elt element);
void enlever(Set* s, Elt element);
int appartient(Set s, Elt element);
int estVide(Set s);
