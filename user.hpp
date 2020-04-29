#ifndef USER_HPP_INCLUDED
#define USER_HPP_INCLUDED
class User
{
protected:
	string FName,LName,Username,Email,Password;
public:
	User()
	{
		FName="";
		LName="";
		Username="";
		Email="";
		Password="";
	}
	User(string FN,string LN,string U,string E,string P)
	{
		FName=FN;
		LName=LN;
		Username=U;
		Email=E;
		Password=P;
	}
	User(const User& u)
    {
        FName=u.FName;
		LName=u.LName;
		Username=u.Username;
		Email=u.Email;
		Password=u.Password;

    }
    void setupUser() //unos korisnika
    {
    	cout << "First name: ";
    	cin >> FName;
    	cout << "Last name: ";
    	cin >> LName;
    	cout << "Username: ";
    	cin >> Username;
    	cout << "Email: ";
    	cin >> Email;
    	string P;
    	while(1)
    	{
    		cout << "Password(8-16 karaktera sa bar 1 malim, velikim slovom i brojem): ";
    		cin >> P;
    		int n=P.size();
    		bool v=false,m=false,b=false;
    		for(int i=0;i<n;i++)
   			{
   				if(v&&m&&b)
   					break;
    			if(!v)
    			{
    				if(P[i]>='A' && P[i]<='Z')
    					v=true;
    			}
    			if(!m)
    			{
    				if(P[i]>='a' && P[i]<='z')
    					m=true;
    			}
    			if(!b)
    			{
    				if(P[i]>='0' && P[i]<='9')
    					b=true;
    			}
    		}
    		if(v&&m&&b)
    			break;
    		cout << endl << "Greska! Pokusajte ponovo." << endl;
    	}
    	setPassword(P);
    	cout << endl << "Welcome " << FName << " " << LName << " to pterodactyl panel!" << endl;
    }


	string getFName()const
	{
		return FName;
	}
	string getLName()const
	{
		return LName;
	}
	string getUsername()const
	{
		return Username;
	}
	string getEmail()const
	{
		return Email;
	}
	string resetPassword() //promena sifre, za slucaj da je zaboravljena
	{
		Password="PromeniMe123";
		return Password;
	}
	string setFName(string FName1)
	{
		FName=FName1;
	}
	string setLName(string LName1)
	{
		LName=LName1;
	}
	string setUsername(string Username1)
	{
		Username=Username1;
	}
	string setEmail(string Email1)
	{
		Email=Email1;
	}
	string setPassword(string Password1)
	{
		Password=Password1;
	}
};
class Admin:public User
{
protected:
	static unsigned short adminID;
public:
	Admin():User() {}
    Admin(string FN,string LN,string U,string E,string P,unsigned short ID):User(FN,LN,U,E,P)
    {
    	adminID=ID;
    }
    Admin(const Admin& a):User(a)
    {
    	adminID=a.adminID;
    }
    Admin(const User& u, unsigned short ID):User(u)
    {
    	adminID=ID;
    }
    void setupAdmin()
    {
    	adminID++;
    	User::setupUser();
    }
};
class SUAdmin:public Admin
{
private:
	bool SU;
public:
	SUAdmin():Admin()
	{
		SU=true;
	}
    SUAdmin(string FN,string LN,string U,string E,string P,unsigned short ID):Admin(FN,LN,U,E,P,ID)
    {
    	SU=true;
    }
    SUAdmin(const SUAdmin& a):Admin(a)
    {
    	//adminID=a.adminID;
    }
    SUAdmin(const Admin& u/*, unsigned short ID*/):Admin(u)
    {
    	//adminID=ID;
    }
    void setupSUAdmin()
    {
    	SU=true;
    	Admin::setupAdmin();
    }
};

#endif // USER_HPP_INCLUDED