#include "jeu.h"

//Affiche les résultat d'un tour de jeu
void jouerTour(const Vecteur<Joueur>& joueurs)
{
  //Variables
  Vecteur<Carte> table;
  Deck deck;

  //Pioche initiale des joueurs
  drawStep(joueurs, deck);

  cout<<"=========Nouveau tour========="<<endl;
  cout<<"===========PREFLOP============"<<endl;
  //Affichage
  afficherJoueurs(joueurs, table);

  cout<<"\n\n=============FLOP============="<<endl;
  //On agrandit la taille du board;
  table.resize(3);
  //On pioche 3 fois
  for(int i=0; i<3; i++)
  {
    table[i]=deck.draw();
  }
  //Affichage
  afficherTable(table);
  afficherJoueurs(joueurs, table);


  cout<<"\n\n=============TURN============="<<endl;
  //On agrandit la taille du board;
  table.resize(4);
  //On pioche 1 fois
  table[3]=deck.draw();
  //Affichage
  afficherTable(table);
  afficherJoueurs(joueurs, table);

  cout<<"\n\n=============RIVER============"<<endl;
  //On agrandit la taille du board;
  table.resize(5);
  //On pioche 1 fois
  table[4]=deck.draw();
  //Affichage
  afficherTable(table);
  afficherJoueurs(joueurs, table);
}

//Appelle la fonction draw sur chacun des joueurs avec le deck donné
void drawStep(const Vecteur<Joueur>& joueurs, Deck& deck)
{
  for (int i=0; i<joueurs.size(); i++)
  {
    joueurs[i].draw(deck);
  }
}

//Affiche les cartes présente sur le board
void afficherTable(const Vecteur<Carte>& table)
{
  cout<<"\nBOARD"<<endl;
  for (int i=0; i<table.size(); i++)
  {
    cout<<table[i]<<endl;
  }
}

//Affiche le nom des joueurs, le contenu de leur main
//et la meilleure combinaison qu'ils ont avec le board passé en paramètre
void afficherJoueurs(const Vecteur<Joueur>& joueurs, const Vecteur<Carte>& table)
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
    cout<<endl<<joueurs[i]<<endl;

    //Affichage des meilleures cartes
    afficherCombinaison(cartes);
    cout<<endl;
  }
}
