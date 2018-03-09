#include "menu.h"

int main (int argc, char *argv[])
{
	alerte** altTab=NULL;
	altTab=malloc(sizeof(alerte*));
	*altTab=malloc(sizeof(alerte));

	int* iAltSize=NULL;
	iAltSize=malloc(sizeof(int));
	*iAltSize=0;


	unite** uniTab=NULL;
	uniTab=malloc(sizeof(unite*));
	*uniTab=malloc(sizeof(unite));

	int* iUniSize=NULL;
	iUniSize=malloc(sizeof(int));
	*iUniSize=0;

	menuPrincipal(altTab, iAltSize, uniTab, iUniSize);

	free(*uniTab);
	free(uniTab);
	free(*altTab);
	free(altTab);

	return 0;
}
