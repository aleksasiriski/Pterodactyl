#ifndef USER_HPP_INCLUDED
#define USER_HPP_INCLUDED

class User
{
protected:
	string FName,LName,Username,Email,Password;
public:
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
	string resetPassword()const
	{
		return "promenime123";
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

#endif // USER_HPP_INCLUDED