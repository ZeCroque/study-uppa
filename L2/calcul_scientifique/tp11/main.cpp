#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
  cout<<"9 en base 2 : "<<convertIntToBase(9,2)<<endl;
  cout<<"15 en base 16 : "<<convertIntToBase(15,16)<<endl;
  cout<<"2/7 en base 2 : "<<convertFloatToBase(2, 7 ,2)<<endl;

  //Je me suis basé sur les cours d'Architecture de Mr. Cariou pour ce code, et, bien qu'il utilise la même norme que vous, il utilise une mantisse m€[0.5,1[
  //Si vous voulez le vérifier, il me semble que le code fonctionne avec cette définition (l'exemple présent ici vient dudit cours)
  //Cordialement
  string nbr="01000101010110011001100110011001";
  cout<<nbr<<" en base 10 : "<<convertIEEE754ToFloat(nbr)<<endl;
  cout<<"716.8 en base 2 : "<<convertFloatToIEEE754(716.8)<<endl;

  return 0;
}
