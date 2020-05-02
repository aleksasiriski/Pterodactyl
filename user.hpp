#ifndef USER_HPP_INCLUDED
#define USER_HPP_INCLUDED
#include <algorithm>
#include <cstdlib>
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
    		cout << "Password(8-16 chars with atleast one big, small letter and number): ";
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
            fflush(stdin); //brise sve uneto posle praznog karaktera
    		if(v&&m&&b)
    			break;
    		cout << endl << "Weak password! Try again." << endl;
    	}
    	setPassword(P);
    	cout << endl << "Welcome " << FName << " " << LName << " to Pterodactyl panel!" << endl;
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
    string generateChar(int iterations,string charset)const
    {
        int n=charset.size();
        string str;
        unsigned short counter=0;
        while(counter!=iterations)
        {
            int tmp=rand()%n;
            str[counter++]=charset[tmp];
        }
        str[counter]='\0';
        return str;
    }
	string resetPassword() //promena sifre, za slucaj da je zaboravljena
	{
        string Password="";
        int n=3;
        Password+=generateChar(n,"0123456789");
        Password+=generateChar(n,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        Password+=generateChar(n,"abcdefghijklmnopqrstuvwxyz");
        n=Password.size();
        for(int i=0;i<10;i++)
        {
            int indexa=rand()%n;
            int indexb=rand()%n;
            Password[indexa]^=Password[indexb];
            Password[indexb]^=Password[indexa];
            Password[indexa]^=Password[indexb];
        }
        return Password;
	}
	void setFName(string FName1)
	{
		FName=FName1;
	}
	void setLName(string LName1)
	{
		LName=LName1;
	}
	void setUsername(string Username1)
	{
		Username=Username1;
	}
	void setEmail(string Email1)
	{
		Email=Email1;
	}
	void setPassword(string Password1)
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

#endif // USER_HPP_INCLUDED
