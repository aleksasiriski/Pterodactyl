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
	string resetPassword()
	{
		Password="promenime123";
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
//nesto
}
class Student: public Osoba
{
private:
    int brojIndeksa;
public:
    Student():Osoba("lola", "lolic", 6), brojIndeksa(1) {}
    Student(string i, string p, int g, int ind):Osoba(i, p, g), brojIndeksa(ind) {}
    Student(const Student& s):Osoba(s), brojIndeksa(s.brojIndeksa) {}
    Student(const Osoba& o, int brojInd):Osoba(o), brojIndeksa(brojInd) {}
    void predstaviSe()
    {
        Osoba::predstaviSe();
        cout<<"I broj mog indeksa je: "<<brojIndeksa<<endl;
    }

};

#endif // USER_HPP_INCLUDED