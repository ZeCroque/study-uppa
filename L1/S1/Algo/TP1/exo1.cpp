#include <iostream>
using namespace std;

int main()
{
	int note=0;
	do
	{
		cout<<"Entrez la note"<<endl;
		cin>>note;
	}
	while(note>20 || note < 0);
	if (note<10)
		cout<<"Insuffisant"<<endl;
	else if (note<12)
		cout<<"Passable"<<endl;
	else if (note<14)
		cout<<"Assez Bien"<<endl;
	else if (note<16)
		cout<<"Bien"<<endl;
	else
		cout<<"Très bien"<<endl;
	return 0;
}	
