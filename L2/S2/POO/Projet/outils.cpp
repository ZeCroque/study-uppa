#include "outils.h"

using namespace std;

//Menu de DEBUG
void debugMode()
{
  Vecteur<Carte> table;

  table.push_back(Carte(9,1));
  table.push_back(Carte(10,1));
  table.push_back(Carte(11,1));
  table.push_back(Carte(13,1));
  table.push_back(Carte(12,1));
  table.push_back(Carte(1,2));

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
