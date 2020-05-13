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
void pocetak()
{
	loadUsers(userfile);
	loadAdmins(adminfile);
	Admin::globalID=admins.rbegin()->getadminID();
}
void kraj()
{
	saveUsers(userfile);
	saveAdmins(adminfile);
}
int main()
{
	srand(time(NULL)); //seed za rand()
    pocetak();

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
	setupUser(&u);
	cout << u;
	//cout << Marko.resetPassword() << endl;
	//Marko.changePassword();

	Admin a;
	setupAdmin(&a);
	cout << a;
	//cout << Aleksa.resetPassword() << endl;
	//Aleksa.changePassword();

	/*predlog funkcionalnosti: napraviti u lokaciju, node i dodeliti server obicnom useru*/

	/*predlog funkcionalnosti: napraviti jos jedan server na istom node i istoj lokaciji koji je
	dodeljen adminu*/

	/*predlog funkcionalnosti: dodati novi node u istoj lokaciji sa jos jednim serverom i dodeliti ga
	nekom useru, a zatim nakon provere da funkcionise obrisati server i user a ostaviti node u memoriji*/

	kraj();
	return 0;
}
