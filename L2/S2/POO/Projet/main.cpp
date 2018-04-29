#include <iostream>
#include <time.h>
#include <cstdlib>
#include "deck.h"
#include "vecteur.h"
#include "joueur.h"
#include "jeu.h"
#include "outils.h"

using namespace std;

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
    Deck deck;
    drawStep(joueurs, deck);

    cout<<"=========Nouveau tour========="<<endl;
    cout<<"===========PREFLOP============"<<endl;
    table.resize(0);
    afficherJoueurs(joueurs, table);

    cout<<"\n\n=============FLOP============="<<endl;
    table.resize(3);
    for(int i=0; i<3; i++)
    {
      table[i]=deck.draw();
    }
    afficherTable(table);
    afficherJoueurs(joueurs, table);


    cout<<"\n\n=============TURN============="<<endl;
    table.resize(4);
    table[3]=deck.draw();
    afficherTable(table);
    afficherJoueurs(joueurs, table);

    cout<<"\n\n=============RIVER============"<<endl;
    table.resize(5);
    table[4]=deck.draw();
    afficherTable(table);
    afficherJoueurs(joueurs, table);

  /*  //DEBUG//
    table.push_back(Carte(2,1));
    table.push_back(Carte(5,3));
    table.push_back(Carte(7,1));
    table.push_back(Carte(1,1));
    table.push_back(Carte(13,2));

    afficherTable(table);
    afficherJoueurs(joueurs, table);*/


    //Choix de rejouer
    do
    {
      cout<<"\n\nJouer un autre tour ? (y/n)"<<endl;
      newTurn=readBool();
    } while(newTurn==-1);
  }

  return 0;
}
