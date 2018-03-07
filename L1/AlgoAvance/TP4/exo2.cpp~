#include<iostream>
using namespace std;

typedef struct
{
	string nom;
	int nbr;
	float prix;
} article;

typedef struct
{
	article art;
	int nbr;
	float prix;
} commande;

int main()
{
	int loop=1, n, ref, i;
	
	article centrifugeuse={"Centrifugeuse",33,35.0};
	article grillePain={"Grille-Pain",12,29.90};
	article fourRaclette={"Four a raclette",6,44.90};
	commande facture[3];
	facture[0].art=centrifugeuse;
	facture[1].art=grillePain;
	facture[2].art=fourRaclette;
	for(i=0;i<3;i++)
	{
		facture[i].nbr=0;
		facture[i].prix=0;
		cout<<facture[i].prix<<" "<<facture[i].nbr<<" "<<facture[i].art.nom<<endl;
	}	
	


	
	/*do
	{
		do
		{
			
		}
	} while(loop);*/

	return 0;
}

