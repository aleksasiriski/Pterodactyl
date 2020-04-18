#ifndef LOCATION_HPP_INCLUDED
#define LOCATION_HPP_INCLUDED
#include "node.hpp"

class Location
{
private:
	string CC;
	Node N;
public:
	Location()
	{
		CC="RS";
	}
	Location(string C)
	{
		CC=C;
	}
	void setCC(string C)
	{
		CC=C;
	}
	void getCC()const
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
	int setRAM(int RA)
	{
		N.setRAM(RA);
	}
	int getROM()const
	{
		return N.getROM();
	}
	int setROM(int RO)
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
	int setARAM(int ARA)
	{
		N.setARAM(ARA);
	}
	int getAROM()const
	{
		return N.getAROM();s
	}
	int setAROM(int ARO)
	{
		N.setAROM(ARO);
	}
};

#endif // LOCATION_HPP_INCLUDED