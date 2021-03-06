#ifndef USER_HPP_INCLUDED
#define USER_HPP_INCLUDED
#include "picosha2.h"
string makeHash(string input)
{
    return picosha2::hash256_hex_string(input);
}
class User
{
protected:
	string FName,LName,Username,Email,Password;
    vector<Node*> nodes;
public:
	User(string FN="",string LN="",string U="",string E="",string P="")
	{
		FName=FN;
		LName=LN;
		Username=U;
		Email=E;
		Password=P;
	}
    ~User()
    {
        string userfile=Username+".txt";
        ofstream file(userfile);
        for(auto i=nodes.begin();i!=nodes.end();i++)
            file<<**i<<endl;
        file.close();
    }
	User(const User& u)
    {
        FName=u.FName;
		LName=u.LName;
		Username=u.Username;
		Email=u.Email;
		Password=u.Password;

    }
    void pushNode(Node* n)
    {
        nodes.push_back(n);
    }
    void ListNodes()
    {
        if(nodes.empty())
        {
            cout << "Nodes do not exist.\n";
            return;
        }
        int counter=1;
        for(auto i=nodes.begin();i!=nodes.end();i++)
            cout << counter++ << ") " << **i << endl;
        cout<<"Continue...";
        char cont;
        cin >> cont;
    }
    virtual bool isadmin(){return false;}
    virtual void setup() //unos korisnika
    {
    	cout << "\tFirst name >>> ";
    	cin >> FName;
    	cout << "\tLast name >>> ";
    	cin >> LName;
    	cout << "\tUsername >>> ";
    	cin >> Username;
    	cout << "\tEmail >>> ";
    	cin >> Email;
    	changePassword(false);
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
    string getPassword()const //TREBA DODATI ENKRIPCIJU, OVO SE KORISTI ZA FAJL
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
	void resetPassword() //promena sifre, za slucaj da je zaboravljena
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
        cout<<Password<<endl;
        Password=makeHash(Password);
        cout<<"Continue...";
        char cont;
        cin >> cont;
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
	void changePassword(bool newP=true)
	{
		string P;
        while(newP)
        {
            cout << "\tEnter current password >>> ";
            cin >> P;
            if(makeHash(P)==Password)
                break;
            cout << "\tIncorrect password! Try again.\n";
        }
        while(1)
        {
            cout << "\tPassword(8-16 chars with atleast one big, small letter and number) >>> ";
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
        Password=makeHash(P);
	}
    friend ostream& operator<<(ostream& output, const User& u)
    {
        output<<u.FName<<" "<<u.LName<<" "<<u.Username<<" "<<u.Email<<" "<<endl;
        return output;
    }
};
class Admin:public User
{
protected:
    unsigned short adminID;
    static unsigned short globalID;
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
    static void setGlobalID(unsigned short ID=0)
    {
        globalID=ID;
    }
    friend ostream& operator<<(ostream& output, const Admin& a)
    {
        output<<a.FName<<" "<<a.LName<<" "<<a.Username<<" "<<a.Email<<" "<<a.adminID<<endl;
        return output;
    }
};

#endif // USER_HPP_INCLUDED
