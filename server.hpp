#ifndef SERVER_HPP_INCLUDED
#define SERVER_HPP_INCLUDED
#include "database.hpp"
class Server
{
private:
	string Name;
	int CPU,RAM,ROM;
	Database DB;
public:
	Server():DB()
	{
		Name="";
		CPU=1;
		RAM=2;
		ROM=5;
	}
	Server(string N,int C,int RA,int RO,string dbname,string dbip,string dbuser,string dbpassword):DB(dbname,dbip,dbuser,dbpassword)
	{
		Name=N;
		CPU=C;
		RAM=RA;
		ROM=RO;
	}
	string getDB()const
	{
		return DB.getDB();
	}
	void setDB(string dbname,string dbip,string dbuser,string dbpassword)
	{
		DB.setDB(dbname,dbip,dbuser,dbpassword);
	}
	int getCPU()const
	{
		return CPU;
	}
	void setCPU(int C)
	{
		CPU=C;
	}
	int getRAM()const
	{
		return RAM;
	}
	void setRAM(int RA)
	{
		RAM=RA;
	}
	int getROM()const
	{
		return ROM;
	}
	void setROM(int RO)
	{
		ROM=RO;
	}
	friend ostream& operator<<(ostream& output, const Server& s)
    {
        output<<"Name: "<<" ";
        output<<"CPU: "<<s.CPU<<" ";
        output<<"RAM: "<<s.RAM<<" ";
        output<<"ROM: "<<s.ROM<<" ";
        output<<s.DB;
        return output;
    }
};

#endif // SERVER_HPP_INCLUDED
