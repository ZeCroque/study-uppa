#include <iostream>
#include <time.h>
#include <cstdlib>
#include "vecteur.h"
#include "joueur.h"
#include "jeu.h"
#include "outils.h"

#ifndef DEBUG_MODE
#define DEBUG_MODE 42
#endif

using namespace std;

int main()
{
  //Initialise l'aléatoire
  srand(time(NULL));

  //Variables
  int playerCount=0;
  int newTurn=1;
  Vecteur<Joueur> joueurs;
  bool saisieOK=true;


  //Choix du nombre de joueurs
  //On recommence tant que l'utilisateur n'entre pas une valeur entre 2 et 10
  //Ou la valeur cachée pour entrer en debugMode
  do
  {
      if(saisieOK)
      {
        cout<<"Entrez le nombre de joueur (2-10) :"<<endl;
      }
      playerCount=readUnsignedInt();
      if (playerCount<2 || (playerCount>10 && playerCount!=DEBUG_MODE))
      {
        saisieOK=false;
      }
      else
      {
        saisieOK=true;
      }
      if(!saisieOK)
      {
        cout<<"La valeur n'est pas dans l'interval demandé, veuillez saisir à nouveau."<<endl;
      }
  } while(!saisieOK);


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
  //Sinon entrée en debugMode
  else
  {
    debugMode();
  }


  return 0;
}
