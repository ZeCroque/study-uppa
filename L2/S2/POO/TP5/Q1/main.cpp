#include <iostream>
#include "etudiant.h"
#include "enseignant.h"

using namespace std;

int main()
{
  Etudiant e1("Jean", "Moulin", 1415);
  Etudiant e2(e1);
  Etudiant e3=e1;
  Enseignant en("Joe", "LeRelou", "Professeur de type abstrait");
  Personne p("John", "Do");
  Personne p2("Alan", "Smithee");

  cout<<"\n\n===Pointeurs===\n\n";

  Personne* pp=NULL;
  pp=&e1;
  pp->afficher();
  pp=&en;
  pp->afficher();
  pp=&p;
  pp->afficher();

  cout<<"\n\n===Tableau===\n\n";

  Personne** tab=new Personne*[6];
  tab[0]=&e1;
  tab[1]=&e2;
  tab[2]=&e3;
  tab[3]=&en;
  tab[4]=&p;
  tab[5]=&p2;

  for(int i=0; i<6; i++)
  {
    tab[i]->afficher();
  }



  return 0;
}
