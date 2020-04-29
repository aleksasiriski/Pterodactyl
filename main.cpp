#include <iostream>
using namespace std;
#include "location.hpp"
#include "nestandpack.hpp"
#include "user.hpp"
int Admin::adminID=0; //brojac ID admina
int main()
{
	Location First; // pravi jednu lokaciju sa jednim node i jednim serverom i jednim database

	User Marko; // obican user
	Marko.setupUser(); // inicijalizacija obicnog usera

	/*predlog funkcionalnosti: napraviti lokaciju i sve pod njom kao gore, sa dodeljenim cpu, ram i rom
	i dodeliti taj jedan server obicnom useru*/

	SUAdmin Aleksa; // super admin, veci od admina
	Aleksa.setupSUAdmin(); // inicijalizacija super admina

	/*predlog funkcionalnosti: napraviti jos jedan server na istom node i istoj lokaciji koji je
	dodeljen adminu, ali da admin moze upravljati i serverom obicnog usera*/
	
	/*predlog funkcionalnosti: dodati novi node u istoj lokaciji sa jos jednim serverom i dodeliti ga
	nekom useru, a zatim nakon provere da funkcionise obrisati server i user a ostaviti node u memoriji*/

	/*predlog funkcionalnosti: dodati novu lokaciju node i 2 servera dodeljena 2 normalna usera*/

	return 0; //zatvoriti program sa svim izmenama sacuvanim u fajlu
}