#include "combinaison.h"

//****************************
//*        AFFICHAGE         *
//****************************

//Affiche la meilleur combinaison dans les cartes données en paramètre
//Appelles toutes les fonctions de vérification dans leur ordre hiérarchique
//S'arrête lorsque l'une d'elle est trouvée ou affiche la carte haute
void afficherCombinaison(const Vecteur<Carte>& cartes)
{
    cout<<"MEILLEURE COMBINAISON"<<endl;
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
      afficherCarteHaute(cartes);
    }
}

//Affiche le kicker parmi les cartes passées en paramètre
//Exceptée les cartes dont la hauteur se trouve dans valeurExclues (on exclue du kicker les cartes composant la combinaison)
//Affiche un nombre de kicker égal au paramètre "number"
void afficherKicker(const Vecteur<Carte>& cartes, Vecteur<int> valeursExclues, int number)
{
  Carte tmp;

  cout<<"\nKicker: ";
  for(int i=0; i<number; i++)
  {
    tmp=trouverCarteHaute(cartes, valeursExclues);
    if (tmp.getValeur()!=0)
    {
      valeursExclues.push_back(tmp.getValeur());
      cout<<tmp.afficherValeur();
      if(i!=number-1)
      {
        cout<<" ";
      }
    }
  }
}

//Affiche la carte haute et 4 kickers
void afficherCarteHaute(const Vecteur<Carte>& cartes)
{
  Carte hauteur=trouverCarteHaute(cartes);
  cout<<"Carte haute : ";
  cout<<hauteur.afficherValeur();
  Vecteur<int> valeursExclues;
  valeursExclues.push_back(hauteur.getValeur());
  afficherKicker(cartes, valeursExclues, 4);
}

//****************************
//*          OUTILS          *
//****************************

//Renvoie la hauteur d'une combinaison composée de "number" cartes si possible
//Sinon renvoie la carte par défaut
Carte trouverCartesEgales(const Vecteur<Carte>& cartes, int number, int valeurExclue=0)
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

    if(k==number-1 && cartes[i].getValeur()!=valeurExclue && ((cartes[i].getValeur()>hauteur.getValeur() && hauteur.getValeur()!=1) || cartes[i].getValeur()==1))
    {
      hauteur=cartes[i];
    }
  }

  return hauteur;
}

//Renvoie la carte de hauteur la plus haute parmi les cartes données
//Excepté les cartes dont la hauteur se trouve dans valeurExclues
Carte trouverCarteHaute(const Vecteur<Carte>& cartes, const Vecteur<int>& valeursExclues)
{
  Carte hauteur;
  for (int i=0; i<cartes.size(); i++)
  {
    if((cartes[i].getValeur()>hauteur.getValeur() &&  hauteur.getValeur()!=1) || cartes[i].getValeur()==1)
    {
      bool estDansValeursExclues=false;
      for(int j=0; j<valeursExclues.size() && !estDansValeursExclues; j++)
      {
        if(cartes[i].getValeur()==valeursExclues[j])
        {
          estDansValeursExclues=true;
        }
      }
      if (!estDansValeursExclues)
      {
        hauteur=cartes[i];
      }
    }
  }
  return hauteur;
}

//******************************
//*VERIFICATION DE COMBINAISONS*
//******************************

//**POUR TOUTES LES FONCTIONS SUIVANTES**
//Vérifie si la combinaison concernée est présente dans les cartes passées en paramètre
//Affiche puis renvoie vrai si la combinaison s'y trouve
//Retourne faux sinon

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
    cout<<hauteurmax.afficherValeur();
    return true;
  }
  //Sinon on retourne un résultat négatif
  return false;
}

bool verifierCarre(const Vecteur<Carte>& cartes)
{
  Carte hauteur=trouverCartesEgales(cartes, 4);

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

    cout<<hauteur.afficherValeur();
    Vecteur<int> valeursExclues;
    valeursExclues.push_back(hauteur.getValeur());
    afficherKicker(cartes, valeursExclues, 1);
    return true;
  }
  return false;
}

bool verifierFull(const Vecteur<Carte>& cartes)
{
  Carte hauteur=trouverCartesEgales(cartes, 3);
  Carte hauteur2;

  if (hauteur.getValeur()!=0)
  {
    hauteur2=trouverCartesEgales(cartes, 2);
    if (hauteur2.getValeur()!=0)
    {
      cout<<"Full aux ";
      cout<<hauteur.afficherValeur();
      cout<<" par les ";
      cout<<hauteur2.afficherValeur();
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

    if(k==4 && ((cartes[i].getValeur()>hauteur.getValeur() && hauteur.getValeur()!=1) || cartes[i].getValeur()==1))
    {
      hauteur=cartes[i];
    }
  }

  if (hauteur.getValeur()!=0)
  {
    cout<<"Couleur à ";
    cout<<hauteur.afficherFamille();
    cout<<" hauteur ";
    cout<<hauteur.afficherValeur();
    return true;
  }
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
    cout<<hauteurmax.afficherValeur();
    return true;
  }
  //Sinon on retourne un résultat négatif
  return false;
}

bool verifierBrelan(const Vecteur<Carte>& cartes)
{
  Carte hauteur=trouverCartesEgales(cartes, 3);

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

    cout<<hauteur.afficherValeur();
    Vecteur<int> valeursExclues;
    valeursExclues.push_back(hauteur.getValeur());
    afficherKicker(cartes, valeursExclues, 2);
    return true;
  }
  return false;
}

bool verifierDoublePaire(const Vecteur<Carte>& cartes)
{
  Carte hauteur=trouverCartesEgales(cartes, 2);
  Carte hauteur2;

  if (hauteur.getValeur()!=0)
  {
    hauteur2=trouverCartesEgales(cartes, 2 , hauteur.getValeur());
    if (hauteur2.getValeur()!=0)
    {
      cout<<"Double paire : ";
      cout<<hauteur.afficherValeur();
      cout<<" et ";
      cout<<hauteur2.afficherValeur();
      Vecteur<int> valeursExclues;
      valeursExclues.push_back(hauteur.getValeur());
      valeursExclues.push_back(hauteur2.getValeur());
      afficherKicker(cartes, valeursExclues, 1);
      return true;
    }
  }
  return false;
}

bool verifierPaire(const Vecteur<Carte>& cartes)
{
  Carte hauteur=trouverCartesEgales(cartes, 2);

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

    cout<<hauteur.afficherValeur();
    Vecteur<int> valeursExclues;
    valeursExclues.push_back(hauteur.getValeur());
    afficherKicker(cartes, valeursExclues, 3);
    return true;
  }
  return false;
}
