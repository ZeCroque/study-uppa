#include "outils.h"

using namespace std;

//Menu de DEBUG
void debugMode()
{
  Vecteur<Carte> table;
  int valeur=0;
  int famille=0;

  for (int i=0; i<7 && valeur!=DEBUG_MODE && famille!=DEBUG_MODE; i++)
  {
    do
    {
      cout<<"Entrez la valeur de la carte "<<table.size()+1<<" (1-13; "<<DEBUG_MODE<<" pour arrêter)"<<endl;
      valeur=readUnsignedInt();
    } while (valeur>13 && valeur!=DEBUG_MODE);
    if(valeur!=DEBUG_MODE)
    {
      do
      {
        cout<<"Entrez la famille de la carte "<<table.size()+1<<"\n1: Trèfle\n2: Pique\n3: Carreau\n4: Coeur\n"<<DEBUG_MODE<<": arrêter"<<endl;
        famille=readUnsignedInt();
      } while(famille>4 && famille!=DEBUG_MODE);
      if(famille!=DEBUG_MODE)
      {
        table.push_back(Carte(valeur,famille));
        cout<<table[table.size()-1]<<endl;
      }
    }
  }

  afficherTable(table);
  cout<<endl;
  afficherCombinaison(table);
  cout<<endl;
}

//TODO TRY/CATCH
//Permet de demander à l'utilisateur un entier non signé
//En évitant les erreurs de lecture
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

//TODO TRY/CATCH
//Permet de demander à l'utilisateur un booléen
//En évitant les erreurs de lecture
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
