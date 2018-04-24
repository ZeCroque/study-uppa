#include <iostream>
#include <time.h>
#include <cstdlib>
#include <sstream>
#include <string.h>
#include "deck.h"
#include "vecteur.h"
#include "joueur.h"

using namespace std;

unsigned int readUnsignedInt();
int readBool();
string intToString(int number);
void afficherTable(const Vecteur<Carte>& table);
void drawStep(const Vecteur<Joueur>& joueurs, Deck& deck);
void verifierCombinaison(const Vecteur<Joueur>& joueurs, const Vecteur<Carte>& table);

int main()
{
  //Initialise l'aléatoire
  srand(time(NULL));

  //Variables
  int playerCount=0;
  int newTurn=1;
  Vecteur<Joueur> joueurs;
  Vecteur<Carte> table;

  //Choix du nombre de joueurs
  do
  {
    cout<<"Entrez le nombre de joueur :"<<endl;
    playerCount=readUnsignedInt();
  } while(playerCount<2 || playerCount>10);

  //Création des joueurs
  joueurs.resize(playerCount);
  for (int i=0; i<playerCount; i++)
  {
    joueurs[i]=Joueur("Joueur "+ intToString(i+1));
  }

  //Début du jeu
  while(newTurn)
  {
    /*Deck deck;
    drawStep(joueurs, deck);

    cout<<"=========Nouveau tour========="<<endl;
    cout<<"===========PREFLOP============"<<endl;
    //afficherJoueurs(joueurs);
    verifierCombinaison(joueurs, table);

    cout<<"\n\n=============FLOP============="<<endl;
    table.resize(3);
    for(int i=0; i<3; i++)
    {
      table[i]=deck.draw();
    }
    verifierCombinaison(joueurs, table);
    //afficherTable(table);

    cout<<"\n\n=============TURN============="<<endl;
    table.resize(4);
    table[3]=deck.draw();
    verifierCombinaison(joueurs, table);
    //afficherTable(table);

    cout<<"\n\n=============RIVER============"<<endl;
    table.resize(5);
    table[4]=deck.draw();
    verifierCombinaison(joueurs, table);
    //afficherTable(table);*/

    //DEBUG//
    table.push_back(Carte(11,1));
    table.push_back(Carte(12,1));
    table.push_back(Carte(13,1));
    table.push_back(Carte(1,2));
    table.push_back(Carte(10,1));
    table.push_back(Carte(9,1));
    verifierCombinaison(joueurs, table);
    //afficherTable(table);


    //Choix de rejouer
    do
    {
      cout<<"Jouer un autre tour ? (y/n)"<<endl;
      newTurn=readBool();
    } while(newTurn==-1);
  }

  return 0;
}

bool verifierQuinteFlush(Vecteur<Carte> cartes)
{
  int supCount;
  Carte hauteurmax; //Hauteur max trouvée lors de la recherche de suite

  //Parcours de toute les cartes
  for(int i=0; i<cartes.size(); i++)
  {
    //Variables
    Carte tmp=cartes[i];  //Tampon pour stocker la carte que l'on compare aux autres
    Carte hauteur;  //Tampon qui stocke la hauteur de suite la plus grande trouvée jusqu'ici
    bool supTrouve=false; //Booléen indiquant si l'on a trouvé une hauteur plus grande que le tampon
    supCount=0; //Compteur du nombre de fois qu'une hauteur plus grande que le tampon est trouvé

    //Boucle qui recommencera tant que l'on trouvera une carte plus grande que celle examinée
    do
    {
      int j=0;
      supTrouve=false;

      //Parcoure les cartes à partir de 0 jusqu'à arriver à la fin du tableau OU jusqu'à trouver une carte qui répondes aux critères suivants :
      //1 - La hauteur de la carte est supérieure à celle du tampon ET le tampon n'est pas un roi (13)
      //        OU
      //    Le tampon est un roi (13) ET la carte est un as (1)
      //2 - La couleur de la carte est la même que celle du tampon
      while(j!=cartes.size() && ((tmp.getValeur()==13 && cartes[j].getValeur()!=1) || (tmp.getValeur()+1!=cartes[j].getValeur() && tmp.getValeur()!=13) || tmp.getFamille()!=cartes[j].getFamille()))
      {
        j++;
      }

      //Si le while a trouvé une carte correspondant aux critères précédents (fin du tableau non atteite)
      if(j!=cartes.size())
      {
        //On incrémente le compteur, met dans le tampon la carte trouvée, et l'on indique qu'il faut recommencer
        supCount++;
        tmp=cartes[j];
        supTrouve=true;
      }
    } while(supTrouve);

    //Si l'on vient de déterminer que 4 cartes ou plus suivent la première
    if(supCount>3)
    {
      //L'on fixe le tampon de hauteur à la carte la plus haute que l'on a examinée
      hauteur=tmp;
      //Si ledit tampon est plus grand que la hauteur max précédemment enregistrée
      if(hauteur.getValeur()>hauteurmax.getValeur() || hauteur.getValeur()==1)
      {
        //La hauteur max devient le tampon
        hauteurmax=hauteur;
      }
    }
  }

  //Si l'on a trouvé une quinte (la hauteur max est différente de celle par défaut)
  if(hauteurmax.getValeur()!=0)
  {
    //On affiche et retourne un résultat positif
    cout<<"Quinte flush hauteur "<<hauteurmax<<endl;
    return true;
  }
  //Sinon on retourne un résultat négatif
  return false;
}

bool verifierQuinte(Vecteur<Carte> cartes)
{
  int supCount;
  Carte hauteurmax; //Hauteur max trouvée lors de la recherche de suite

  //Parcours de toute les cartes
  for(int i=0; i<cartes.size(); i++)
  {
    //Variables
    Carte tmp=cartes[i];  //Tampon pour stocker la carte que l'on compare aux autres
    Carte hauteur;  //Tampon qui stocke la hauteur de suite la plus grande trouvée jusqu'ici
    bool supTrouve=false; //Booléen indiquant si l'on a trouvé une hauteur plus grande que le tampon
    supCount=0; //Compteur du nombre de fois qu'une hauteur plus grande que le tampon est trouvé

    //Boucle qui recommencera tant que l'on trouvera une carte plus grande que celle examinée
    do
    {
      int j=0;
      supTrouve=false;

      //Parcoure les cartes à partir de 0 jusqu'à arriver à la fin du tableau OU jusqu'à trouver une carte qui répondes aux critères suivants :
      //    La hauteur de la carte est supérieure à celle du tampon ET le tampon n'est pas un roi (13)
      //        OU
      //    Le tampon est un roi (13) ET la carte est un as (1)
      while(j!=cartes.size() && ((tmp.getValeur()==13 && cartes[j].getValeur()!=1) || (tmp.getValeur()+1!=cartes[j].getValeur() && tmp.getValeur()!=13)))
      {
        j++;
      }

      //Si le while a trouvé une carte correspondant aux critères précédents (fin du tableau non atteite)
      if(j!=cartes.size())
      {
        //On incrémente le compteur, met dans le tampon la carte trouvée, et l'on indique qu'il faut recommencer
        supCount++;
        tmp=cartes[j];
        supTrouve=true;
      }
    } while(supTrouve);

    //Si l'on vient de déterminer que 4 cartes ou plus suivent la première
    if(supCount>3)
    {
      //L'on fixe le tampon de hauteur à la carte la plus haute que l'on a examinée
      hauteur=tmp;
      //Si ledit tampon est plus grand que la hauteur max précédemment enregistrée
      if(hauteur.getValeur()>hauteurmax.getValeur() || hauteur.getValeur()==1)
      {
        //La hauteur max devient le tampon
        hauteurmax=hauteur;
      }
    }
  }

  //Si l'on a trouvé une quinte (la hauteur max est différente de celle par défaut)
  if(hauteurmax.getValeur()!=0)
  {
    //On affiche et retourne un résultat positif
    cout<<"Quinte hauteur "<<hauteurmax<<endl;
    return true;
  }
  //Sinon on retourne un résultat négatif
  return false;
}



void verifierCombinaison(const Vecteur<Joueur>& joueurs, const Vecteur<Carte>& table)
{
  //Compteurs
  int i, j, k;

  for (i=0; i<joueurs.size(); i++)
  {
    //Initialisation d'un vecteur à la taille de la main du joueur+celle du board
    Vecteur<Carte> cartes;
    cartes.resize(joueurs[i].getMain().size()+table.size());

    //Remplissage du tableau nouvellement créé
    //D'abord avec la main du joueur
    for (j=0; j<joueurs[i].getMain().size(); j++)
    {
      cartes[j]=joueurs[i].getMain()[j];
    }
    //Puis avec le board
    for(k=0; k<table.size(); k++, j++)
    {
      cartes[j]=table[k];
    }

    //Affichage de la main du joueur
    cout<<joueurs[i]<<endl;

    //Affichage du total des cartes
    cout<<"CARTES AVEC LE BOARD"<<endl;
    for(j=0; j<cartes.size(); j++)
    {
      cout<<cartes[j]<<endl;
    }


    //Affichage des meilleures cartes
    bool combinaisonTrouvee=false;
    combinaisonTrouvee=verifierQuinteFlush(cartes);
    if(!combinaisonTrouvee)
    {
      combinaisonTrouvee=verifierQuinte(cartes);
    }
    //TODO
    //Autre vérifs
  }
}

void drawStep(const Vecteur<Joueur>& joueurs, Deck& deck)
{
  for (int i=0; i<joueurs.size(); i++)
  {
    joueurs[i].draw(deck);
  }
}

void afficherTable(const Vecteur<Carte>& table)
{
  for (int i=0; i<table.size(); i++)
  {
    cout<<table[i]<<endl;
  }
}

unsigned int readUnsignedInt()
{
  string input="";
  unsigned int result=0;

  cin>>input;
  for(unsigned int i=0; i<input.size(); i++)
  {
    if(input[i]<='0' && input[i]>='9')
    {
      return -1;
    }
    result*=10;
    result+=input[i]-'0';
  }
  return result;
}

int readBool()
{
  string input="";
  cin>>input;

  if(input!="y" && input!="n")
  {
    return -1;
  }
  return input=="y";
}

string intToString(int number)
{
  stringstream stream;
  stream<<number;
  return stream.str();
}
