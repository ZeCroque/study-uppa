#include <iostream>
using namespace std;

int main()
{
	float n, R=0;

	do
	{
		cout<<"Entrez le revenu imposable"<<endl;
		cin>>R;
		cout<<"Entrez le nombre de part"<<endl;
		cin>>n;
	} while (R<0 || n<0);

	if (R/n<=4121)
		cout<<"0€"<<endl;
	else if (R/n<=8104)
		cout<<R*0.075 - 309.08*n<<"€"<<endl;
	else if (R/n<=14264)
		cout<<R*0.21 - 1403.12*n<<"€"<<endl;
	else if (R/n<=23096)
		cout<<R*0.31 - 2829.52*n<<"€"<<endl;
	else if (R/n<=37579)
		cout<<R*0.41 - 5139.12*n<<"€"<<endl;
	else if (R/n<=46343)
		cout<<R*0.4675 - 7299.91*n<<"€"<<endl;
	else if (R/n>46343)
		cout<<R*0.5275 - 10080.49*n<<"€"<<endl;

	return 0;
}
