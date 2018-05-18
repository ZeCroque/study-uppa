#include "outils.h"

using namespace std;

//Menu de DEBUG
void debugMode()
{
  Vecteur<Carte> table;
  int valeur=0;
  int famille=0;
  bool saisieOK=true;


  cout<<"=======DEBUG MODE======="<<endl;
  for (int i=0; i<7 && valeur!=DEBUG_MODE && famille!=DEBUG_MODE; i++)
  {
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
    if(valeur!=DEBUG_MODE && valeur!=0)
    {
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

      if(famille!=DEBUG_MODE && famille!=0)
      {
        table.push_back(Carte(valeur,famille));
        cout<<endl<<table[table.size()-1]<<endl<<endl;
      }
    }
  }

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
  string input="";
  unsigned int result=0;

  cin>>input;

  try
  {
    for(unsigned int i=0; i<input.size(); i++)
    {

        if(input[i]<'0' || input[i]>'9')
        {
          throw INPUT_ERROR;
        }
        result*=10;
        result+=input[i]-'0';
    }
  }
  catch(int errorcode)
  {
    if(errorcode==INPUT_ERROR)
    {
      cout<<"Valeur incorrecte, veuillez saisir à nouveau."<<endl;
      return readUnsignedInt();
    }
  }
  return result;
}

//Permet de demander à l'utilisateur un booléen
//En évitant les erreurs de lecture
bool readBool()
{
  string input="";
  cin>>input;

  try
  {
    if(input!="y" && input!="n")
    {
      throw INPUT_ERROR;
    }
  }
  catch(int errorcode)
  {
    if(errorcode==INPUT_ERROR)
    {
      cout<<"Valeur incorrecte, veuillez saisir à nouveau."<<endl;
      return readBool();
    }
  }

  return input=="y";
}

string intToString(int number)
{
  stringstream stream;
  stream<<number;
  return stream.str();
}
