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
    virtual bool isadmin(){return false;}
    virtual void setup() //unos korisnika
    {
    	cout << "First name: ";
    	cin >> FName;
    	cout << "Last name: ";
    	cin >> LName;
    	cout << "Username: ";
    	cin >> Username;
    	cout << "Email: ";
    	cin >> Email;
    	changePassword();
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
    string getPassword() //TREBA DODATI ENKRIPCIJU, OVO SE KORISTI ZA FAJL
    {
        return Password;
    }
    string generateChars(int iterations,string charset)const
    {
        int n=charset.size(),counter=0;
        string str="";
        while(counter!=iterations)
        {
            int tmp=rand()%n;
            str+=charset[tmp];
            counter++;
        }
        return str;
    }
	string resetPassword() //promena sifre, za slucaj da je zaboravljena
	{
        int n=3; //kvadrirano daje duzinu sifre
        Password="";
        Password+=generateChars(n,"0123456789");
        Password+=generateChars(n,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        Password+=generateChars(n,"abcdefghijklmnopqrstuvwxyz");
        n=Password.size();
        for(int i=0;i<10;i++)
        {
            int indexa=rand()%n;
            int indexb=rand()%n;
            char tmp=Password[indexa];
            Password[indexa]=Password[indexb];
            Password[indexb]=tmp;
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
    /*void setPassword(string P) //SAMO ZA TESTIRANJE
    {
        Password=P;
    }*/
	void changePassword()
	{
		string P;
        while(1)
        {
            cout << "Password(8-16 chars with atleast one big, small letter and number): ";
            cin >> P;
            int n=P.size();
            bool v=false,m=false,b=false;
            if(n>=8 && n<=16)
            {
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
            }
            fflush(stdin); //brise sve uneto posle praznog karaktera
            if(v&&m&&b)
                break;
            cout << endl << "Weak password! Try again." << endl;
        }
        Password=P;
	}
    virtual unsigned short getadminID()const
    {
        return 0;
    }
    friend ostream& operator<<(ostream& output, const User& u)
    {
        output<<"Output of user:"<<endl;
        output<<"First name: "<<u.FName<<endl;
        output<<"Last name: "<<u.LName<<endl;
        output<<"Username: "<<u.Username<<endl;
        output<<"Email: "<<u.Email<<endl;
        return output;
    }
};
class Admin:public User
{
protected:
    unsigned short adminID;
public:
    static unsigned short globalID;
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
    bool isadmin(){return true;}
    void setup()
    {
        User::setup();
        adminID=++globalID;
    }
    unsigned short getadminID()const
    {
        return adminID;
    }
    friend ostream& operator<<(ostream& output, const Admin& a)
    {
        output<<"Output of user:"<<endl;
        output<<"First name: "<<a.FName<<endl;
        output<<"Last name: "<<a.LName<<endl;
        output<<"Username: "<<a.Username<<endl;
        output<<"Email: "<<a.Email<<endl;
        output<<"ID: "<<a.adminID<<endl;
        return output;
    }
};

vector<User> users;
vector<Admin> admins;
void loadUsers(string filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        string FName,LName,Username,Email,Password;
        while(!file.eof())
        {
            file>>FName>>LName>>Username>>Email>>Password;
            User* u(FName,LName,Username,Email,Password);
            users.push_back(u);
        }
        file.close();
    }
    else
        cout << "Unable to open file.";
}
void listUsers()
{
    for(auto i=users->begin();i!=users->end();i++)
        cout<<i->getFName()<<endl;
}
void saveUsers(string filename)
{
    ofstream file(filename);
    for(auto i=users->begin();i!=users->end();i++)
    {
        file<<i->getFName()<<" ";
        file<<i->getLName()<<" ";
        file<<i->getUsername()<<" ";
        file<<i->getEmail()<<" ";
        file<<i->getPassword()<<endl;
    }
    file.close();
}
void loadAdmins(string filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        string FName,LName,Username,Email,Password;
        unsigned short adminID;
        while(!file.eof())
        {
            file>>FName>>LName>>Username>>Email>>Password>>adminID;
            Admin* a(FName,LName,Username,Email,Password,adminID);
            admins.push_back(a);
        }
        file.close();
    }
    else
        cout << "Unable to open file.";
}
void listAdmins()
{
    for(auto i=admins->begin();i!=admins->end();i++)
        cout<<i->getFName()<<endl;
}
void saveAdmins(string filename)
{
    ofstream file(filename);
    for(auto i=admins->begin();i!=admins->end();i++)
    {
        file<<i->getFName()<<" ";
        file<<i->getLName()<<" ";
        file<<i->getUsername()<<" ";
        file<<i->getEmail()<<" ";
        file<<i->getPassword()<<" ";
        file<<i->getadminID()<<endl;
    }
    file.close();
}

void setup(User* u)
{
    u->setup();
    if(u->isadmin())
        admins.push_back(u);
    else
        users.push_back(u);
}

#endif // USER_HPP_INCLUDED
