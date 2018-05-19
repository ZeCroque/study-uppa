#include "outils.h"

using namespace std;

//Menu de DEBUG
void debugMode()
{
  //Variables
  Vecteur<Carte> table;
  int valeur=0;
  int famille=0;
  bool saisieOK=true;


  cout<<"=======DEBUG MODE======="<<endl;
  //On demande une saisie de carte à l'utilisateur
  //Jusqu'à un maximum de sept Cartes
  //OU jusqu'à ce que l'utilisateur force l'arrêt
  for (int i=0; i<7 && valeur!=DEBUG_MODE && famille!=DEBUG_MODE; i++)
  {
    //Lecture contrainte de la valeur de la carte
    //Jusqu'à ce que l'utilisateur rentre une valeur comprise entre 1 et 13
    //OU force l'arrêt
    do
    {
        if(saisieOK)
        {
          cout<<"=======CARTE "<<table.size()+1<<"=======\nEntrez la valeur de la carte (1-13; "<<DEBUG_MODE<<" pour arrêter)"<<endl;
        }
        valeur=readUnsignedInt();
        if (valeur<1 || (valeur>13 && valeur!=DEBUG_MODE))
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

    cout<<endl;
    saisieOK=true;
    //Si l'utilisateur n'a pas arrêté la saisie
    if(valeur!=DEBUG_MODE)
    {
      //Lecture contrainte de la famille de la carte
      //Jusqu'à ce que l'utilisateur rentre une valeur comprise entre 1 et 4
      //OU force l'arrêt
      do
      {
          if(saisieOK)
          {
            cout<<"Entrez la famille de la carte "<<table.size()+1<<"\n1: Trèfle\n2: Pique\n3: Carreau\n4: Coeur\n"<<DEBUG_MODE<<": arrêter"<<endl;
          }
          famille=readUnsignedInt();
          if (famille<1 || (famille>4 && famille!=DEBUG_MODE))
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

      //Si l'utilisateur n'a pas arrêté la saisie
      if(famille!=DEBUG_MODE)
      {
        //On crée la carte demandée
        table.push_back(Carte(valeur,famille));
        //On l'affiche
        cout<<endl<<table[table.size()-1]<<endl<<endl;
      }
    }
  }

  //Affichage des cartes saisies et des combinaisons
  cout<<"\n=======BILAN======="<<endl;
  afficherTable(table);
  cout<<endl;
  afficherCombinaison(table);
  cout<<endl;
}

//Permet de demander à l'utilisateur un entier non signé
//En évitant les erreurs de lecture
unsigned int readUnsignedInt()
{
  //Variables
  string input="";
  unsigned int result=0;

  //Mets la valeur du flux d'entrée dans un tampon
  cin>>input;

  try
  {
    //Parcourre toutes les caractères du string tampon
    for(unsigned int i=0; i<input.size(); i++)
    {
        //Si un des caractères n'est pas un chiffre
        if(input[i]<'0' || input[i]>'9')
        {
          //Lance une erreur
          throw INPUT_ERROR;
        }
        //Sinon on multiplie par 10 le resultat afin de respecter unité/dizaine/centaine etc...
        result*=10;
        //Et on ajoute la valeur du caractère moins le caratère 0 afin d'avoir la valeur numérique correspondante
        result+=input[i]-'0';
    }
  }
  catch(int errorcode)
  {
    //Si l'on a catch une exception du bon type
    if(errorcode==INPUT_ERROR)
    {
      //On affiche un message d'erreur
      cout<<"Valeur incorrecte, veuillez saisir à nouveau."<<endl;
      //On appelle recursivement la fonction
      return readUnsignedInt();
    }
  }
  //On renvoie le résultat une fois qu'il est correct
  return result;
}

//Permet de demander à l'utilisateur un booléen
//En évitant les erreurs de lecture
bool readBool()
{
  string input="";

  //Mets la valeur du flux d'entrée dans un tampon
  cin>>input;

  try
  {
    //Si le tampon est différent du string "y" ou du string "n"
    if(input!="y" && input!="n")
    {
      //On lance une erreur
      throw INPUT_ERROR;
    }
  }
  catch(int errorcode)
  {
    if(errorcode==INPUT_ERROR)
    {
      //On affiche un message d'erreur
      cout<<"Valeur incorrecte, veuillez saisir à nouveau."<<endl;
      //On appelle recursivement la fonction
      return readBool();
    }
  }

  //On return un booléen valant vrai si le string "y" et faux si c'est "n"
  return input=="y";
}

//Permet de convertir un entier donné en son équivalent en caractères
string intToString(int number)
{
  stringstream stream;
  stream<<number;
  return stream.str();
}
