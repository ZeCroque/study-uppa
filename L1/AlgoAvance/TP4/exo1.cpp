#include <iostream>
using namespace std;

typedef struct 
{
	string nom;
	int jDebut;
	string mDebut;
	int jFin;
	string mFin;
} signe;

int main()
{
	signe all[12];
	int i,j,mi;
	string m;
	
	signe capricorne ={"Capricorne",23,"Decembre",19,"Janvier"};
	all[0]=capricorne;
	signe verseau = {"Verseau",20,"Janvier",19,"Fevrier"};
	all[1]=verseau;
	signe poisson = {"Poisson",20,"Fevrier",20,"Mars"};
	all[2]=poisson;
	signe belier={"Belier",21,"Mars",19,"Avril"};
	all[3]=belier;
	signe taureau={"Taureau",20,"Avril",20,"Mai"};
	all[4]=taureau;
	signe gemeau={"Gemeau",21,"Mai",20, "Juin"};
	all[5]=gemeau;
	signe cancer={"Cancer",21,"Juin",21,"Juillet"};
	all[6]=cancer;
	signe lion={"Lion",22,"Juillet",22,"Aout"};
	all[7]=lion;
	signe vierge={"Vierge",23,"Aout",22,"Septembre"};
	all[8]=vierge;
	signe balance={"Balance",23,"Septembre",22,"Octobre"};
	all[9]=balance;
	signe scorpion={"Scorpion",23,"Octobre",22,"Novembre"};
	all[10]=scorpion;
	signe sagittaire={"Sagittaire",23,"Novembre",22,"Decembre"};
	all[11]=sagittaire;
	
	do
	{
		mi=-1;
		cout<<"Entrez le mois de votre naissance"<<endl;
		cin>>m;
		for(i=0;i<12;i++)
			if (m==all[i].mFin)
				mi=i+1;
		
	} while (mi==-1);

	do
	{
			cout<<"Entrez le jour de votre naissance"<<endl;
			cin>>j;
	} while (j<1 || (j>31 && mi%2==0 && mi>5) || (j>31 && mi%2!=0 && mi!=2 && mi<6) || (j>30 && mi%2!=0 && mi>5) || (j>30 && mi%2==0 && mi<6) || (j>29 && mi==2));

	for(i=0; i<12; i++)
	{
		if (m==all[i].mDebut && j>=all[i].jDebut)
			cout<<all[i].nom<<endl;
		else if (m==all[i].mFin && j<=all[i].jFin)
			cout<<all[i].nom<<endl;
	} 

	



	return 0;	
}
