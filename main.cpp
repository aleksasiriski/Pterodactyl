#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#define MAX 100
using namespace std;
//#include "file.hpp"
#include "location.hpp"
#include "eggnestpack.hpp"
#include "user.hpp"
unsigned short Admin::adminID=0; //brojac ID admina
int main()
{
    srand(time(NULL)); //seed za rand()
    loadUsers("users.txt");
    listUsers();
    loadAdmins("admins.txt");
    listAdmins();


	//Location First; // pravi jednu lokaciju sa jednim node i jednim serverom i jednim database

	//User Marko;
	//setupUser(Marko);
	//cout << Marko.resetPassword() << endl;
	//Marko.changePassword();

	/*Admin Aleksa;
	setupAdmin(Aleksa);
	cout << Aleksa.resetPassword() << endl;
	Aleksa.changePassword();*/

	/*predlog funkcionalnosti: napraviti lokaciju i sve pod njom kao gore, sa dodeljenim cpu, ram i rom
	i dodeliti taj jedan server obicnom useru*/

	//Admin Aleksa; // admin
	//Aleksa.setupAdmin(); // inicijalizacija super admina

	/*predlog funkcionalnosti: napraviti jos jedan server na istom node i istoj lokaciji koji je
	dodeljen adminu, ali da admin moze upravljati i serverom obicnog usera*/

	/*predlog funkcionalnosti: dodati novi node u istoj lokaciji sa jos jednim serverom i dodeliti ga
	nekom useru, a zatim nakon provere da funkcionise obrisati server i user a ostaviti node u memoriji*/

	/*predlog funkcionalnosti: dodati novu lokaciju node i 2 servera dodeljena 2 normalna usera*/

	return 0; //zatvoriti program sa svim izmenama sacuvanim u fajlu
}
