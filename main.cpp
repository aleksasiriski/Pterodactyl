#include "panel.hpp"
unsigned short Admin::globalID=0;
int main()
{
	srand(time(NULL)); //seed za rand()
	Panel p;
	p.CreateUser();

	/*funkcionalnost 1: napraviti u lokaciju, node i dodeliti server obicnom useru*/

	/*funkcionalnost 2: napraviti jos jedan server na istom node i istoj lokaciji koji je
	dodeljen adminu*/

	/*funkcionalnost 3: pretraga za user i admin i nekim nepostojecim user i admin*/

	/*funkcionalnost 4: dodati novi node u istoj lokaciji sa jos jednim serverom i dodeliti ga
	nekom useru, a zatim nakon provere da funkcionise obrisati server i user a ostaviti node u memoriji*/
	return 0;
}
