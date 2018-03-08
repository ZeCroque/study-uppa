#include <stdlib.h>
#include <stdio.h>
//#include <error.h>

#define TAILLE 30

typedef struct{
	int iCode;
	char sDesignation[TAILLE];
	int iTaille;
	float fHT;
} Article;

int creerArticle(Article ** article, int icode, char * sDesignation, int iTaille, float fPu);
void afficherArticle(Article * article);
void detruireArticle (Article ** pArt);


