#include <iostream>
#include <time.h>
#include <cstdlib>
#include "vecteur.h"
#include "joueur.h"
#include "jeu.h"
#include "outils.h"

#define DEBUG_MODE 42

using namespace std;

int main()
{
  //Initialise l'aléatoire
  srand(time(NULL));

  //Variables
  int playerCount=0;
  int newTurn=1;
  Vecteur<Joueur> joueurs;

  //Choix du nombre de joueurs
  //On recommence tant que l'utilisateur n'entre pas une valeur entre 2 et 10
  //Ou la valeur cachée pour entrer en debugMode
  do
  {
    cout<<"Entrez le nombre de joueur (2-10) :"<<endl;
    playerCount=readUnsignedInt();
  } while(playerCount<2 || (playerCount>10 && playerCount!=DEBUG_MODE));

  //Si l'on est pas en debug mode
  if(playerCount!=DEBUG_MODE)
  {
    //Création des joueurs
    joueurs.resize(playerCount);
    for (int i=0; i<playerCount; i++)
    {
      joueurs[i]=Joueur("Joueur "+ intToString(i+1));
    }

    //Début du jeu
    while(newTurn)
    {
      jouerTour(joueurs);

      //Choix de rejouer
      do
      {
        cout<<"\n\nJouer un autre tour ? (y/n)"<<endl;
        newTurn=readBool();
      } while(newTurn==-1);
    }
  }
  //Entrée en debugMode
  else
  {
    debugMode();
  }


  return 0;
}
