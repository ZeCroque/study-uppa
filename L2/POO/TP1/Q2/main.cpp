#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  char strNom[50];
  char strPrenom[50];
  char strConcatenee[100];
  string strConcatenee2;

  cin>>strNom;
  cin>>strPrenom;

  strcpy(strConcatenee, strNom);
  strcat(strConcatenee, strPrenom);
  cout<<strConcatenee<<endl;

  strConcatenee2=strNom;
  strConcatenee2+=strPrenom;
  cout<<strConcatenee2<<endl;

  return 0;
}
