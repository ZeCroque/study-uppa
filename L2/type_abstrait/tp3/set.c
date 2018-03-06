#include "set.h"

Set vide()
{
	Set s=NULL;

	return s;
}

void ajouter(Set* s, Elt element)
{
	Set temp=malloc(sizeof(Cellule));
	Set aux=*s;
	(*temp).elem=element;

	if(aux!=NULL)
	{
		while(((*aux).suiv!=NULL) && (*aux).elem!=element)
		{
			aux=(*aux).suiv;
		}
		if ((*aux).elem!=element)
		{
			(*aux).suiv=temp;
			(*temp).suiv=NULL;
		}
	}
	else
	{
		(*s)=temp;
	}

}

int appartient(Set s, Elt element)
{
	Set aux=s;

	if (!estVide(aux))
	{
		while(((*aux).suiv!=NULL) && (*aux).elem!=element)
		{
			aux=(*aux).suiv;
		}

		if ((*aux).elem!=element)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	return 0;

}

void enlever(Set* s, Elt element)
{
	Set aux=*s;
	Set tmp=NULL;
	if(aux->elem==element)
	{
		tmp=aux;

		if ((*s)->suiv!=NULL)
		{
			*s=aux->suiv;
		}
		else
		{
			*s=NULL;
		}

		free(tmp);
	}
	else
	{
			printf("chatte");
		while(((*aux).suiv!=NULL) && ((*aux).suiv)->elem!=element)
		{
			aux=(*aux).suiv;
		}

		if (((*aux).suiv)->elem==element)
		{
			tmp=aux->suiv;
			aux->suiv=tmp->suiv;
			free(tmp);
		}
	}
}

int estVide(Set s)
{
	if (s==NULL)
	{
		return 1;
	}
	return 0;
}
