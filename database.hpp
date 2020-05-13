#ifndef DATABASE_HPP_INCLUDED
#define DATABASE_HPP_INCLUDED
class Database
{
private:
	string dbname,dbip,dbuser,dbpassword;
public:
	Database()
	{
		dbname="";
		dbip="";
		dbuser="";
		dbpassword="";
	}
	Database(string name,string ip,string user,string password)
	{
		dbname=name;
		dbip=ip;
		dbuser=user;
		dbpassword=password;
	}
	string getDB()const
	{
		return "'"+dbname+"'@'"+dbip+"' using "+dbuser;
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
	friend ostream& operator<<(ostream& output, const Database& db)
    {
        output<<"Output of DB:"<<endl;
        output<<"DB Name: "<<db.dbname<<endl;
        output<<"DB IP: "<<db.dbip<<endl;
        output<<"DB User: "<<db.dbuser<<endl;
        output<<"DB Password: "<<db.dbpassword<<endl;
        return output;
    }
};

#endif // DATABASE_HPP_INCLUDED