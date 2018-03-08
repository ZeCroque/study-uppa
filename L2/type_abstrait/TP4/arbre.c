#include"arbre.h"

void construireArbre(Arbre* a)
{
  *a=NULL;
}

void insererEltArbre(Arbre* a, Element elt)
{
  int i=0;

  if(a!=NULL && *a==NULL)
  {
    *a=malloc(sizeof(Noeud));
    (*a)->e=elt;
    (*a)->fils=NULL;
  }
  else if(a!=NULL && *a!=NULL)
  {
    if((*a)->fils!=NULL)
    {
      for (i=0; ((*a)->fils)[i]!=NULL; i++);
      printf("i:%d\n",i);
      (*a)->fils=realloc((*a)->fils, i*sizeof(Arbre));
      (((*a)->fils)[i])=malloc(sizeof(Noeud));
      (((*a)->fils)[i])->e=elt;
      (((*a)->fils)[i])->fils=NULL;
    }
    else
    {
      printf("i:0\n");
      (*a)->fils=malloc(sizeof(Arbre));
      (*(*a)->fils)=malloc(sizeof(Noeud));
      (*(*a)->fils)->e=elt;
      (*(*a)->fils)->fils=NULL;
    }
  }
}

int estArbreVide(Arbre A)
{
  if(A==NULL)
  {
    return 1;
  }
  return 0;
}

Arbre fils(Arbre A, int index)
{
  return ((A->fils)[index]);
}

Element racine(Arbre A)
{
  return A->e;
}

Arbre* listeSousArbre(Arbre A)
{
  return A->fils;
}

int nombreSousArbre(Arbre A)
{
  int i=0;

  for (i=0; (A->fils)[i]!=NULL; i++)
  {
    printf("%d\n",racine(fils(A,i)));
  }

  return i-2;
}
