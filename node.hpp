#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED
#include "server.hpp"

class Node()
{
private:
	int ACPU,ARAM,AROM;
	server S;
public:
	Node()
	{
		ACPU=2;
		ARAM=16;
		AROM=100;
		S.setCPU(1);
		S.setRAM(2);
		S.setROM(5);
		S.setDB("","","","");
	}
	Node(int AC,int ARA,int ARO,int C,int RA,int RO,string dbname,string dbip,string dbuser,string dbpassword)
	{
		ACPU=AC;
		ARAM=ARA;
		AROM=ARO;
		S.setCPU(C);
		S.setRAM(RA);
		S.setROM(RO);
		S.setDB(dbname,dbip,dbuser,dbpassword);
	}
	string getDB()const
	{
		return S.getDB();
	}
	void setDB(string dbname,string dbip,string dbuser,string dbpassword)
	{
		S.setDB(dbname,dbip,dbuser,dbpassword);
	}
	int getCPU()const
	{
		return S.getCPU;
	}
	void setCPU(int C)
	{
		S.setCPU(C);
	}
	int getRAM()const
	{
		return S.getRAM;
	}
	int setRAM(int RA)
	{
		S.setRAM(RA);
	}
	int getROM()const
	{
		return S.getROM;
	}
	int setROM(int RO)
	{
		S.setROM(RO);
	}
	int getACPU()const
	{
		return ACPU;
	}
	void setACPU(int AC)
	{
		ACPU=AC;
	}
	int getARAM()const
	{
		return ARAM;
	}
	int setARAM(int ARA)
	{
		ARAM=ARA;
	}
	int getAROM()const
	{
		return AROM;
	}
	int setAROM(int ARO)
	{
		AROM=ARO;
	}
};

#endif // NODE_HPP_INCLUDED