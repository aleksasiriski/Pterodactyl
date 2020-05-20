#include "panel.hpp"
#define tmina void
unsigned short Admin::globalID=0;
tmina outputMenu()
{
	system(clear);
	cout << "----- Welcome! What do you want to do? -----\n";
	cout << "\t1) Create a new user\n\t2) List users\n\t3) Search users\n\t4) Delete users\n\t5) Change users\n";
	cout << "\tq) Exit program\n";
	cout << "\t >>> ";
}
int main()
{
	srand(time(NULL)); //seed za rand()
	Panel p;
	while(1)
	{
		outputMenu();
		string choice;
		cin >> choice;
		if(toexit(choice))
			break;
		char choicec=choice[0];
		switch(choicec)
		{
			case '1': p.CreateUser(); break;
			case '2': p.ListUsers(); break;
			case '3': p.SearchUsers(); break;
			case '4': p.DeleteUsers(); break;
			case '5': p.ChangeUsers(); break;
		}
	}

	



	/*funkcionalnost 1: napraviti u lokaciju, node i dodeliti server obicnom useru*/

	/*funkcionalnost 2: napraviti jos jedan server na istom node i istoj lokaciji koji je
	dodeljen adminu*/

	/*funkcionalnost 3: pretraga za user i admin i nekim nepostojecim user i admin*/

	/*funkcionalnost 4: dodati novi node u istoj lokaciji sa jos jednim serverom i dodeliti ga
	nekom useru, a zatim nakon provere da funkcionise obrisati server i user a ostaviti node u memoriji*/
	p.SaveChanges();
	return 0;
}
