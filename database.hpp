#ifndef DATABASE_HPP_INCLUDED
#define DATABASE_HPP_INCLUDED

class database()
{
private:
	string dbname,dbip,dbuser,dbpassword;
public:
	database()
	{
		dbname="";
		dbip="";
		dbuser="";
		dbpassword="";
	}
	database(string name,string ip,string user,string password)
	{
		dbname=name;
		dbip=ip;
		dbuser=user;
		dbpassword=password;
	}
	string getDB()const
	{
		string DB="'"+dbname+"'@'"+
		return DB;
	}
	void setDB(string name,string ip,string user,string password)
	{
		if(name.size()!=0)
			dbname=name;
		if(ip.size()!=0)
			dbip=ip;
		if(user.size()!=0)
			dbuser=user;
		if(password.size()!=0)
			dbpassword=password;
	}
};

#endif // DATABASE_HPP_INCLUDED