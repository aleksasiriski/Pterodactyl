#ifndef LOCATION_HPP_INCLUDED
#define LOCATION_HPP_INCLUDED
#include "node.hpp"
class Location
{
private:
	string CC;
	Node N;
public:
	Location():N()
	{
		CC="RS";
	}
	Location(string CCC,int AC,int ARA,int ARO,int C,int RA,int RO,string dbname,string dbip,string dbuser,string dbpassword)
	:N(AC,ARA,ARO,C,RA,RO,dbname,dbip,dbuser,dbpassword)
	{
		CC=CCC;
	}
	void setCC(string CCC)
	{
		CC=CCC;
	}
	string getCC()const
	{
		return CC;
	}
	string getDB()const
	{
		return N.getDB();
	}
	void setDB(string dbname,string dbip,string dbuser,string dbpassword)
	{
		N.setDB(dbname,dbip,dbuser,dbpassword);
	}
	int getCPU()const
	{
		return N.getCPU();
	}
	void setCPU(int C)
	{
		N.setCPU(C);
	}
	int getRAM()const
	{
		return N.getRAM();
	}
	void setRAM(int RA)
	{
		N.setRAM(RA);
	}
	int getROM()const
	{
		return N.getROM();
	}
	void setROM(int RO)
	{
		N.setROM(RO);
	}
	int getACPU()const
	{
		return N.getACPU();
	}
	void setACPU(int AC)
	{
		N.setACPU(AC);
	}
	int getARAM()const
	{
		return N.getARAM();
	}
	void setARAM(int ARA)
	{
		N.setARAM(ARA);
	}
	int getAROM()const
	{
		return N.getAROM();
	}
	void setAROM(int ARO)
	{
		N.setAROM(ARO);
	}
	friend ostream& operator<<(ostream& output, const Location& l)
    {
        output<<"Output of Location:"<<endl;
        output<<"CC: "<<l.CC<<endl;
        output<<l.N<<endl;
        return output;
    }
};

#endif // LOCATION_HPP_INCLUDED
