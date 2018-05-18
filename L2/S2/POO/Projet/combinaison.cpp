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
  //On effectue number fois l'opération suivante :
  for(int i=0; i<number; i++)
  {
    //On affecte la carte haute dans un tampon en excluant les valeurs données en paramètre
    tmp=trouverCarteHaute(cartes, valeursExclues);
    //Si une carte haute a bien été trouvée
    if (tmp.getValeur()!=0)
    {
      //On l'ajoute aux valeurs exclues
      valeursExclues.push_back(tmp.getValeur());
      //On l'affiche
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
  //On affecte la carte haute dans un tampon
  Carte hauteur=trouverCarteHaute(cartes);

  //Si l'on a bien trouvé une carte haute (tableau non vide)
  if(hauteur.getValeur()!=0)
  {
    //On l'affiche
    cout<<"Carte haute : ";
    cout<<hauteur.afficherValeur();
    //On ajoute dans le vecteur des valeurs exclues le tampon
    Vecteur<int> valeursExclues;
    valeursExclues.push_back(hauteur.getValeur());
    //On affiche 4 kicker en excluant la hauteur trouvée
    afficherKicker(cartes, valeursExclues, 4);
  }
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

  //Pour chaque carte passé en paramètre
  for(int i=0; i<cartes.size(); i++)
  {
    k=0;
    //On la compare à toutes les cartes passées en paramètre
    for(int j=0; j<cartes.size(); j++)
    {
      //Si deux carte on la même valeur
      //ET ce n'est pas la même carte
      if (cartes[i].getValeur()==cartes[j].getValeur() && i!=j)
      {
        //On incrémente un compteur
        k++;
      }
    }

    //Si le compteur a atteint la valeur demandée
    //ET que la valeur de la carte examinée n'est pas dans les valeur exclues
    //ET (que la carte trouvée a une valeur supérieure à la hauteur enregistrée
        //OU  que la carte trouvée est un as)
    if(k==number-1 && cartes[i].getValeur()!=valeurExclue && ((cartes[i].getValeur()>hauteur.getValeur() && hauteur.getValeur()!=1) || cartes[i].getValeur()==1))
    {
      //On affecte au tampon hauteur la carte trouvée
      hauteur=cartes[i];
    }
  }

  //On renvoie une la carte pour indiquer la hauteur de la combinaison
  //OU la carte par défaut si aucune carte n'a été trouvée
  return hauteur;
}

//Renvoie la carte de hauteur la plus haute parmi les cartes données
//Excepté les cartes dont la hauteur se trouve dans valeurExclues
Carte trouverCarteHaute(const Vecteur<Carte>& cartes, const Vecteur<int>& valeursExclues)
{
  Carte hauteur;
  //On parcoure toutes les cartes passées en paramètre
  for (int i=0; i<cartes.size(); i++)
  {
    //Si la carte trouvée a une valeur supérieure à la hauteur enregistrée
    //OU  que la carte trouvée est un as
    if((cartes[i].getValeur()>hauteur.getValeur() &&  hauteur.getValeur()!=1) || cartes[i].getValeur()==1)
    {
      bool estDansValeursExclues=false;
      //On parcoure toute les valeurs exclues
      for(int j=0; j<valeursExclues.size() && !estDansValeursExclues; j++)
      {
        //Si la valeur de la carte s'y trouve
        if(cartes[i].getValeur()==valeursExclues[j])
        {
          //On passe le booléen correspondant à vrai
          estDansValeursExclues=true;
        }
      }
      //Si la carte n'était pas dans les valeurs exclues
      if (!estDansValeursExclues)
      {
        //Le tampon de hauteur prend la valeur de la carte
        hauteur=cartes[i];
      }
    }
  }

  //On renvoie la carte trouvée
  //OU la carte par défaut si aucune carte n'a été trouvée
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
  //On affecte la hauteur renvoyée par la fonction dans un tampon
  Carte hauteur=trouverCartesEgales(cartes, 4);

  //Si le tampon est différent de la carte par défaut
  if (hauteur.getValeur()!=0)
  {
    //Si la carte est un as
    if(hauteur.getValeur()!=1)
    {
      cout<<"Carré de ";
    }
    //Sinon
    else
    {
      cout<<"Carré d'";
    }

    //On affiche la hauteur
    cout<<hauteur.afficherValeur();

    //On ajoute au valeurs exclues la hauteur trouvée
    Vecteur<int> valeursExclues;
    valeursExclues.push_back(hauteur.getValeur());

    //On affiche un kicker excluant la hauteur trouvée
    afficherKicker(cartes, valeursExclues, 1);
    //On renvoie vrai
    return true;
  }
  //Sinon on renvoie faux
  return false;
}

bool verifierFull(const Vecteur<Carte>& cartes)
{
  //On affecte la hauteur renvoyée par la fonction dans un tampon
  Carte hauteur=trouverCartesEgales(cartes, 3);
  Carte hauteur2;

  //Si le tampon est différent de la carte par défaut
  if (hauteur.getValeur()!=0)
  {
    //On affecte la hauteur renvoyée par la fonction dans un tampon
    hauteur2=trouverCartesEgales(cartes, 2);
    //Si le tampon est différent de la carte par défaut
    if (hauteur2.getValeur()!=0)
    {
      //On affiche
      cout<<"Full aux ";
      cout<<hauteur.afficherValeur();
      cout<<" par les ";
      cout<<hauteur2.afficherValeur();
      //On renvoie vrai
      return true;
    }
  }
  //Sinon on renvoie faux
  return false;
}

bool verifierCouleur(const Vecteur<Carte>& cartes)
{
  int k;
  Carte hauteur;

  //Pour chaque carte passé en paramètre
  for(int i=0; i<cartes.size(); i++)
  {
    k=0;

    //On la compare à toutes les cartes passées en paramètre
    for(int j=0; j<cartes.size(); j++)
    {
      //Si deux carte on la même famille
      //ET ce n'est pas la même carte
      if (cartes[i].getFamille()==cartes[j].getFamille() && i!=j)
      {
        //On incrémente un compteur
        k++;
      }
    }


    //Si le compteur a atteint la valeur demandée
    //ET (que la carte trouvée a une valeur supérieure à la hauteur enregistrée
    //OU  que la carte trouvée est un as)
    if(k==4 && ((cartes[i].getValeur()>hauteur.getValeur() && hauteur.getValeur()!=1) || cartes[i].getValeur()==1))
    {
      //On affecte au tampon hauteur la carte trouvée
      hauteur=cartes[i];
    }
  }

  //Si le tampon est différent de la carte par défaut
  if (hauteur.getValeur()!=0)
  {
    //On affiche
    cout<<"Couleur à ";
    cout<<hauteur.afficherFamille();
    cout<<" hauteur ";
    cout<<hauteur.afficherValeur();
    //On renvoie vrai
    return true;
  }
  //Sinon on renvoie faux
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
  //On affecte la hauteur renvoyée par la fonction dans un tampon
  Carte hauteur=trouverCartesEgales(cartes, 3);

  //Si le tampon est différent de la carte par défaut
  if (hauteur.getValeur()!=0)
  {
    //Si la carte est un as
    if(hauteur.getValeur()!=1)
    {
      cout<<"Brelan de ";
    }
    //Sinon
    else
    {
      cout<<"Brelan d'";
    }

    //On affiche la hauteur
    cout<<hauteur.afficherValeur();
    //On ajoute au valeurs exclues la hauteur trouvée
    Vecteur<int> valeursExclues;
    valeursExclues.push_back(hauteur.getValeur());
    //On affiche deux kickers excluant la hauteur trouvée
    afficherKicker(cartes, valeursExclues, 2);
    //On renvoie vrai
    return true;
  }
  //Sinon on renvoie faux
  return false;
}

bool verifierDoublePaire(const Vecteur<Carte>& cartes)
{
  //On affecte la hauteur renvoyée par la fonction dans un tampon
  Carte hauteur=trouverCartesEgales(cartes, 2);
  Carte hauteur2;

  //Si le tampon est différent de la carte par défaut
  if (hauteur.getValeur()!=0)
  {
    //On affecte la hauteur renvoyée par la fonction dans un tampon
    hauteur2=trouverCartesEgales(cartes, 2 , hauteur.getValeur());
    //Si le tampon est différent de la carte par défaut
    if (hauteur2.getValeur()!=0)
    {
      //On affiche
      cout<<"Double paire : ";
      cout<<hauteur.afficherValeur();
      cout<<" et ";
      cout<<hauteur2.afficherValeur();
      //On ajoute au valeurs exclues les hauteurs trouvée
      Vecteur<int> valeursExclues;
      valeursExclues.push_back(hauteur.getValeur());
      valeursExclues.push_back(hauteur2.getValeur());
      //On affiche un kicker excluant la hauteur trouvée
      afficherKicker(cartes, valeursExclues, 1);
      //On renvoie vrai
      return true;
    }
  }
  //Sinon on renvoie faux
  return false;
}

bool verifierPaire(const Vecteur<Carte>& cartes)
{
    //On affecte la hauteur renvoyée par la fonction dans un tampon
  Carte hauteur=trouverCartesEgales(cartes, 2);

  //Si le tampon est différent de la carte par défaut
  if (hauteur.getValeur()!=0)
  {
    //Si la carte est un as
    if(hauteur.getValeur()!=1)
    {
      cout<<"Paire de ";
    }
    //Sinon
    else
    {
      cout<<"Paire d'";
    }

    //On affiche la hauteur
    cout<<hauteur.afficherValeur();
    //On ajoute au valeurs exclues la hauteur trouvée
    Vecteur<int> valeursExclues;
    valeursExclues.push_back(hauteur.getValeur());
        //On affiche trois kickers excluant la hauteur trouvée
    afficherKicker(cartes, valeursExclues, 3);
    //On renvoie vrai
    return true;
  }
  //Sinon on renvoie faux
  return false;
}
