#include <iostream>
using namespace std;
#include "location.hpp"
#include "nestandpack.hpp"
#include "user.hpp"
int main()
{
	Location First; // pravi jednu lokaciju sa jednim node i jednim serverom i jednim database

	User Marko; // obican user
	Marko.setupUser(); // inicijalizacija obicnog usera

	SUAdmin Aleksa; // super admin, veci od admina
	Aleksa.setupSUAdmin(); // inicijalizacija super admina
	
	return 0;
}