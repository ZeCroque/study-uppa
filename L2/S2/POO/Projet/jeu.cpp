#include "jeu.h"

void drawStep(const Vecteur<Joueur>& joueurs, Deck& deck)
{
  for (int i=0; i<joueurs.size(); i++)
  {
    joueurs[i].draw(deck);
  }
}

void afficherTable(const Vecteur<Carte>& table)
{
  cout<<"\nBOARD"<<endl;
  for (int i=0; i<table.size(); i++)
  {
    cout<<table[i]<<endl;
  }
}

void afficherCarte(Carte carte)
{
  switch (carte.getValeur())
  {
    case 1:
      cout<<"As";
      break;
    case 11:
      cout<<"Valet";
      break;
    case 12:
      cout<<"Dame";
      break;
    case 13:
      cout<<"Roi";
      break;
    default:
      cout<<carte.getValeur();
      break;
  }
}

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

    //TODO "Utile de l'afficher?"
    /*//Affichage du total des cartes
    cout<<"CARTES AVEC LE BOARD"<<endl;
    for(j=0; j<cartes.size(); j++)
    {
      cout<<cartes[j]<<endl;
    }*/

    //Affichage des meilleures cartes
    cout<<"MEILLEURE COMBINAISON"<<endl;
    verifierCombinaison(cartes);
    cout<<endl;
  }
}

void verifierCombinaison(const Vecteur<Carte>& cartes)
{

    bool combinaisonTrouvee=false;
    combinaisonTrouvee=verifierQuinteFlush(cartes);
    if(!combinaisonTrouvee)
    {
      combinaisonTrouvee=verifierCarre(cartes);
    }
    if(!combinaisonTrouvee)
    {
      combinaisonTrouvee=verifierFull(cartes);
    }
    if(!combinaisonTrouvee)
    {
      combinaisonTrouvee=verifierCouleur(cartes);
    }
    if(!combinaisonTrouvee)
    {
      combinaisonTrouvee=verifierQuinte(cartes);
    }
    if(!combinaisonTrouvee)
    {
      combinaisonTrouvee=verifierBrelan(cartes);
    }
    if(!combinaisonTrouvee)
    {
      combinaisonTrouvee=verifierDoublePaire(cartes);
    }
    if(!combinaisonTrouvee)
    {
      combinaisonTrouvee=verifierPaire(cartes);
    }
    if(!combinaisonTrouvee)
    {
      cout<<"Carte haute : ";
      afficherCarte(verifierCarteHaute(cartes));
    }
}

bool verifierQuinteFlush(const Vecteur<Carte>& cartes)
{
  int supCount;
  Carte hauteurmax; //Hauteur max trouvée lors de la recherche de suite

  //Parcours de toute les cartes
  for(int i=0; i<cartes.size(); i++)
  {
    //Variables
    Carte tmp=cartes[i];  //Tampon pour stocker la carte que l'on compare aux autres
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

    //Si l'on vient de déterminer que 4 cartes ou plus suivent la première et que le tampon est plus grand que la hauteur max précédemment enregistrée (0 la première fois)
    if(supCount>3 && (tmp.getValeur()>hauteurmax.getValeur() || tmp.getValeur()==1))
    {
      //La hauteur max devient le tampon
      hauteurmax=tmp;
    }
  }

  //Si l'on a trouvé une quinte (la hauteur max est différente de celle par défaut)
  if(hauteurmax.getValeur()!=0)
  {
    //On affiche et retourne un résultat positif
    cout<<"Quinte flush hauteur ";
    afficherCarte(hauteurmax);
    return true;
  }
  //Sinon on retourne un résultat négatif
  return false;
}

bool verifierQuinte(const Vecteur<Carte>& cartes)
{
  int supCount;
  Carte hauteurmax; //Hauteur max trouvée lors de la recherche de suite

  //Parcours de toute les cartes
  for(int i=0; i<cartes.size(); i++)
  {
    //Variables
    Carte tmp=cartes[i];  //Tampon pour stocker la carte que l'on compare aux autres
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

    //Si l'on vient de déterminer que 4 cartes ou plus suivent la première et que le tampon est plus grand que la hauteur max précédemment enregistrée (0 la première fois)

    if(supCount>3 && (tmp.getValeur()>hauteurmax.getValeur() || tmp.getValeur()==1))
    {
        //La hauteur max devient le tampon
        hauteurmax=tmp;
    }
  }

  //Si l'on a trouvé une quinte (la hauteur max est différente de celle par défaut)
  if(hauteurmax.getValeur()!=0)
  {
    //On affiche et retourne un résultat positif
    cout<<"Quinte hauteur ";
    afficherCarte(hauteurmax);
    return true;
  }
  //Sinon on retourne un résultat négatif
  return false;
}

bool verifierCarre(const Vecteur<Carte>& cartes)
{
  int k;
  Carte hauteur;

  for(int i=0; i<cartes.size(); i++)
  {
    k=0;

    for(int j=0; j<cartes.size(); j++)
    {
      if (cartes[i].getValeur()==cartes[j].getValeur() && i!=j)
      {
        k++;
      }
    }

    if(k==3 && (cartes[i].getValeur()>hauteur.getValeur() || cartes[i].getValeur()==1))
    {
      hauteur=cartes[i];
    }
  }

  if (hauteur.getValeur()!=0)
  {
    if(hauteur.getValeur()!=1)
    {
      cout<<"Carré de ";
    }
    else
    {
      cout<<"Carré d'";
    }

    afficherCarte(hauteur);
    return true;
  }
  return false;
}

bool verifierFull(const Vecteur<Carte>& cartes)
{
  int k;
  Carte hauteur;
  Carte hauteur2;

  for(int i=0; i<cartes.size(); i++)
  {
    k=0;

    for(int j=0; j<cartes.size(); j++)
    {
      if (cartes[i].getValeur()==cartes[j].getValeur() && i!=j)
      {
        k++;
      }
    }

    if(k==2 && (cartes[i].getValeur()>hauteur.getValeur() || cartes[i].getValeur()==1))
    {
      hauteur=cartes[i];
    }
  }

  if (hauteur.getValeur()!=0)
  {
    for(int i=0; i<cartes.size(); i++)
    {
      k=0;

      for(int j=0; j<cartes.size(); j++)
      {
        if (cartes[i].getValeur()==cartes[j].getValeur() && i!=j)
        {
          k++;
        }
      }

      if(k==1 && (cartes[i].getValeur()>hauteur2.getValeur() || cartes[i].getValeur()==1))
      {
        hauteur2=cartes[i];
      }
    }
    if (hauteur2.getValeur()!=0)
    {
      cout<<"Full aux ";
      afficherCarte(hauteur);
      cout<<" par les ";
      afficherCarte(hauteur2);
      return true;
    }
  }
  return false;
}

bool verifierCouleur(const Vecteur<Carte>& cartes)
{
  int k;
  Carte hauteur;

  for(int i=0; i<cartes.size(); i++)
  {
    k=0;

    for(int j=0; j<cartes.size(); j++)
    {
      if (cartes[i].getFamille()==cartes[j].getFamille() && i!=j)
      {
        k++;
      }
    }

    if(k==4 && (cartes[i].getValeur()>hauteur.getValeur() || cartes[i].getValeur()==1))
    {
      hauteur=cartes[i];
    }
  }

  if (hauteur.getValeur()!=0)
  {
    cout<<"Couleur hauteur ";
    afficherCarte(hauteur);
    return true;
  }
  return false;
}

bool verifierBrelan(const Vecteur<Carte>& cartes)
{
  int k;
  Carte hauteur;

  for(int i=0; i<cartes.size(); i++)
  {
    k=0;

    for(int j=0; j<cartes.size(); j++)
    {
      if (cartes[i].getValeur()==cartes[j].getValeur() && i!=j)
      {
        k++;
      }
    }

    if(k==2 && (cartes[i].getValeur()>hauteur.getValeur() || cartes[i].getValeur()==1))
    {
      hauteur=cartes[i];
    }
  }

  if (hauteur.getValeur()!=0)
  {
    if(hauteur.getValeur()!=1)
    {
      cout<<"Brelan de ";
    }
    else
    {
      cout<<"Brelan d'";
    }

    afficherCarte(hauteur);
    return true;
  }
  return false;
}

bool verifierDoublePaire(const Vecteur<Carte>& cartes)
{
  int i,k;
  Carte hauteur;
  Carte hauteur2;

  for(i=0; i<cartes.size(); i++)
  {
    k=0;

    for(int j=0; j<cartes.size(); j++)
    {
      if (cartes[i].getValeur()==cartes[j].getValeur() && i!=j)
      {
        k++;
      }
    }

    if(k==1 && (cartes[i].getValeur()>hauteur.getValeur() || cartes[i].getValeur()==1))
    {
      hauteur=cartes[i];
    }
  }

  if (hauteur.getValeur()!=0)
  {
    for(i=0; i<cartes.size(); i++)
    {
      k=0;

      for(int j=0; j<cartes.size(); j++)
      {
        if (cartes[i].getValeur()==cartes[j].getValeur() && i!=j && cartes[i].getValeur()!=hauteur.getValeur())
        {
          k++;
        }
      }

      if(k==1 && (cartes[i].getValeur()>hauteur2.getValeur() || cartes[i].getValeur()==1))
      {
        hauteur2=cartes[i];
      }
    }
    if (hauteur2.getValeur()!=0)
    {
      cout<<"Double paire : ";
      afficherCarte(hauteur);
      cout<<" et ";
      afficherCarte(hauteur2);
      return true;
    }
  }
  return false;
}

bool verifierPaire(const Vecteur<Carte>& cartes)
{
  int k;
  Carte hauteur;

  for(int i=0; i<cartes.size(); i++)
  {
    k=0;

    for(int j=0; j<cartes.size(); j++)
    {
      if (cartes[i].getValeur()==cartes[j].getValeur() && i!=j)
      {
        k++;
      }
    }

    if(k==1 && (cartes[i].getValeur()>hauteur.getValeur() || cartes[i].getValeur()==1))
    {
      hauteur=cartes[i];
    }
  }

  if (hauteur.getValeur()!=0)
  {
    if(hauteur.getValeur()!=1)
    {
      cout<<"Paire de ";
    }
    else
    {
      cout<<"Paire d'";
    }

    afficherCarte(hauteur);
    return true;
  }
  return false;
}

Carte verifierCarteHaute(const Vecteur<Carte>& cartes)
{
  Carte hauteur;
  for (int i=0; i<cartes.size(); i++)
  {
    if(cartes[i].getValeur()>hauteur.getValeur())
    {
      hauteur=cartes[i];
    }
  }
  return hauteur;
}
