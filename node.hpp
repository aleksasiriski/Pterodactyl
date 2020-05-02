#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED
#include "server.hpp"
class Node
{
private:
	int ACPU,ARAM,AROM;
	Server S;
public:
	Node():S()
	{
		ACPU=2;
		ARAM=16;
		AROM=100;
	}
	Node(int AC,int ARA,int ARO,int C,int RA,int RO,string dbname,string dbip,string dbuser,string dbpassword)
	:S(C,RA,RO,dbname,dbip,dbuser,dbpassword)
	{
		ACPU=AC;
		ARAM=ARA;
		AROM=ARO;
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
		return S.getCPU();
	}
	void setCPU(int C)
	{
		S.setCPU(C);
	}
	int getRAM()const
	{
		return S.getRAM();
	}
	void setRAM(int RA)
	{
		S.setRAM(RA);
	}
	int getROM()const
	{
		return S.getROM();
	}
	void setROM(int RO)
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
	void setARAM(int ARA)
	{
		ARAM=ARA;
	}
	int getAROM()const
	{
		return AROM;
	}
	void setAROM(int ARO)
	{
		AROM=ARO;
	}
};

#endif // NODE_HPP_INCLUDED
