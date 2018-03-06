#include "vecteur.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	VecteurChar u;
	u="attentionvousetesfilmes";
	cerr<<u<<'\n';
	u.setKey("test");
	u.encode();
	cout<<u<<'\n';
	u.decode();
	cout<<u<<'n';
}