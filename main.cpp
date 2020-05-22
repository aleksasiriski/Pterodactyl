#define tmina void
#include "panel.hpp"
unsigned short Admin::globalID=0;
tmina LoginScreen()
{
	system(clear);
	cout << "\t ----- Please login -----\n";
	cout << "\tl) Login\n";
	cout << "\te) Exit\n";
	cout << "\t >>> ";
}
tmina outputAdminMenu()
{
	system(clear);
	cout << "----- Admin Panel -----\n";
	cout << "\t1) Create a new user\n\t2) List users\n\t3) Search users\n\t4) Delete users\n\t5) Change users\n";
	cout << "\t6) Add location\n\t7) List locations\n\t8) Delete location\n";
	cout << "\t9) Add node\n\ta) List nodes\n\tb) Delete node\n\tc) Attach node\n";
	cout << "\te) Exit program\n";
	cout << "\t >>> ";
}
tmina outputMenu()
{
	system(clear);
	cout << "----- Welcome! What do you want to do? -----\n";
	cout << "\t1) Change password\n\t2) Reset password\n\t3) List nodes\n";
	cout << "\te) Exit program\n";
	cout << "\t >>> ";
}
tmina adminPanel(Panel& p)
{
	while(1)
	{
		outputAdminMenu();
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
			case '6': p.AddLocation(); break;
			case '7': p.ShowLocations(); break;
			case '8': p.DeleteLocation(); break;
			case '9': p.AddNode(); break;
			case 'a': p.ShowNodes(); break;
			case 'b': p.DeleteNode(); break;
			case 'c': p.AttachNode(); break;
		}
	}
}
tmina userPanel(User* u)
{
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
			case '1': u->changePassword(); break;
			case '2': u->resetPassword(); break;
			case '3': u->ListNodes(); break;
		}
	}
}
tmina Start(Panel& p)
{
	while(1)
	{
		LoginScreen();
		string choice;
		cin >> choice;
		if(toexit(choice))
			break;
		User* u=p.Login();
		if(u->isadmin())
			adminPanel(p);
		else
			userPanel(u);
	}
}
int main()
{
	srand(time(NULL)); //seed za rand()
	Panel p;
	Start(p);
	p.SaveChanges();
	return 0;
}
