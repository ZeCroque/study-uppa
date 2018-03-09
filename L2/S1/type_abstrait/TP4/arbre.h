#ifndef __arbre_h
#define __arbre_h

#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct noeud
{
  Element e;
  struct noeud** fils;
}Noeud;

typedef Noeud* Arbre;

typedef struct tree
{
  Arbre arbre;
  int pos;
  struct tree* suiv;
}Tree;

typedef Tree* Foret;

int estArbreVide(Arbre A);
int estForetVide(Foret A);
Element racine(Arbre A);
Arbre* listeSousArbre(Arbre A);
int nombreSousArbre(Arbre A);
Arbre iemeArbre(Foret F, int index);
int nombreArbre(Foret F);
void insererEltArbre(Arbre* A, Element elt);
void construireArbre(Arbre* a);
void construireForet(Foret* F);
void planterArbre(Foret F, Arbre A);
Arbre fils(Arbre A, int index);



#endif
