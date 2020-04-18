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
		N.setACPU(2);
		N.setARAM(16);
		N.setAROM(100);
		N.setCPU(1);
		N.setRAM(2);
		N.setROM(5);
		N.setDB("","","","");
	}
	Location(string CCC,int AC,int ARA,int ARO,int C,int RA,int RO,string dbname,string dbip,string dbuser,string dbpassword)
	{
		CC=CCC;
		N.setACPU(AC);
		N.setARAM(ARA);
		N.setAROM(ARO);
		N.setCPU(C);
		N.setRAM(RA);
		N.setROM(RO);
		N.setDB(dbname,dbip,dbuser,dbpassword);
	}
	void setCC(string CCC)
	{
		CC=CCC;
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