#include "vector.h"

Vector vide()
{
	Vector v=malloc(sizeof(Cellule));
	(*v).suivant=NULL;
	(*v).pos=-1;
	(*v).elem=0;
	return v;
}

int taille(Vector v)
{
	int i=0;
	Vector aux=v;

	while ((*aux).suivant!=NULL)
	{
		aux=(*aux).suivant;
		i++;
	}
	return i;
}


void inserer(Vector* v, int pos, Elt element)
{
	int i;
	Vector temp=malloc(sizeof(Cellule));
	Vector aux=(*v);


	(*temp).elem=element;
	(*temp).pos=pos;

	if (pos!=0)
	{
		for (i=1; i<pos;i++)
		{
			aux=(*aux).suivant;
		}
		(*temp).suivant=(*aux).suivant;
		(*aux).suivant=temp;
	}
	else
	{
		(*temp).suivant=(*v);
		(*v)=temp;
	}
}

int estVide(Vector v)
{
	if((*v).pos==-1)
	{
		return 1;
	}
	return 0;

}


Vector modifier(Vector v, int pos, Elt element)
{
	Vector temp=malloc(sizeof(Cellule));
	Vector aux=v;
	int i;
	for (i=0 ; i<pos; i++)
	{
		aux=(*aux).suivant;
	}
	(*aux).elem=element;

}

Vector supprimer(Vector* v, int pos)
{
	Vector temp=malloc(sizeof(Cellule));
	Vector aux=(*v);
	int i;
	if (pos!=0)
	{
		for (i=1 ; i<pos; i++)
		{
			aux=(*aux).suivant;
		}

		temp=(*aux).suivant;
		(*aux).suivant=(*temp).suivant;

	}
	else
	{
		temp=(*v);
		(*v)=(*(*v)).suivant;
	}
	free(temp);
}

Elt ieme(Vector v, int pos)
{
	int i;
	Vector aux=v;

	for (i=0;i<pos;i++)
	{
		aux=(*aux).suivant;
	}
	return (*aux).elem;
}
