#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#define MAX 100
using namespace std;
#include "location.hpp"
#include "eggnestpack.hpp"
#include "user.hpp"
unsigned short Admin::globalID=0;
string userfile="users.txt",adminfile="admins.txt";
void startprogram()
{
	loadUsers(userfile);
	loadAdmins(adminfile);
	Admin::globalID=(*(admins.rbegin()))->getadminID();
}
void endprogram()
{
	saveUsers(userfile);
	saveAdmins(adminfile);
}
int main()
{
	srand(time(NULL)); //seed za rand()
    startprogram();

    listUsers();
    cout << endl;
    listAdmins();

	/*Location First;

	Database db;
	cout << db;
    Server s;
    cout << s;
    Node n;
    cout << n;
    Location l;
    cout << l;*/

	User u;
	setup(&u);
	cout << u;
	//cout << Marko.resetPassword() << endl;
	//Marko.changePassword();

	Admin a;
	setup(&a);
	cout << a;
	//cout << Aleksa.resetPassword() << endl;
	//Aleksa.changePassword();

	/*funkcionalnost 1: napraviti u lokaciju, node i dodeliti server obicnom useru*/

	/*funkcionalnost 2: napraviti jos jedan server na istom node i istoj lokaciji koji je
	dodeljen adminu*/

	/*funkcionalnost 3: pretraga za user i admin i nekim nepostojecim user i admin*/

	/*funkcionalnost 4: dodati novi node u istoj lokaciji sa jos jednim serverom i dodeliti ga
	nekom useru, a zatim nakon provere da funkcionise obrisati server i user a ostaviti node u memoriji*/

	endprogram();
	return 0;
}
