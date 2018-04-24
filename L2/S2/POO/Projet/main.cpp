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
    table.push_back(Carte(13,1));
    table.push_back(Carte(12,1));
    table.push_back(Carte(1,1));
    table.push_back(Carte(10,1));
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

void verifierCombinaison(const Vecteur<Joueur>& joueurs, const Vecteur<Carte>& table)
{
  //Compteurs
  int i, j, k, l, m;

  for (i=0; i<joueurs.size(); i++)
  {
    //Initialisation d'un vecteur à la taille de la main du joueur+celle du board
    Vecteur<Carte> cartes;
    cartes.resize(joueurs[i].getMain().size()+table.size());

    //Remplissage du tableau nouvellement créé
    for (j=0; j<joueurs[i].getMain().size(); j++)
    {
      cartes[j]=joueurs[i].getMain()[j];
    }
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

    //Test quinte
    bool quinteTrouvee=false;
    k=0;
    do
    {
      j=0;
      m=0;
      Carte tmp=cartes[k];
      for(l=0; l<cartes.size(); l++)
      {
        if((tmp.getValeur()==13 && cartes[l].getValeur()==1) || tmp.getValeur()+1==cartes[l].getValeur())
        {
          if(tmp.getFamille()==cartes[l].getFamille())
          {
            m++;
          }
          j++;
          tmp=cartes[l];
        }
      }
      for(l=cartes.size()-1; l>0; l--)
      {
        if((tmp.getValeur()==13 && cartes[l].getValeur()==1) || tmp.getValeur()+1==cartes[l].getValeur())
        {
          if(tmp.getFamille()==cartes[l].getFamille())
          {
            m++;
          }
          j++;
          tmp=cartes[l];
        }
      }
      Carte hauteur=tmp;
      if(j<4)
      {
        Carte tmp=cartes[k];
        for(l=0; l<cartes.size(); l++)
        {
          if(tmp.getValeur()!=1 && tmp.getValeur()-1==cartes[l].getValeur())
          {
            if(tmp.getFamille()==cartes[l].getFamille())
            {
              m++;
            }
            j++;
            tmp=cartes[l];
          }
        }
        for(l=cartes.size()-1; l>0; l--)
        {
          if(tmp.getValeur()!=1 && tmp.getValeur()-1==cartes[l].getValeur())
          {
            if(tmp.getFamille()==cartes[l].getFamille())
            {
              m++;
            }
            j++;
            tmp=cartes[l];
          }
        }
      }
      if(j>3)
      {
        if(m<4)
        {
          cout<<"Quinte hauteur "<<hauteur<<endl;
        }
        else
        {
          cout<<"Quinte flush hauteur "<<hauteur<<endl;
        }
        quinteTrouvee=true;
      }

      k++;
    } while(quinteTrouvee==false && k!=cartes.size());

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
