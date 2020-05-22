#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED
#include "server.hpp"
class Node
{
private:
	string Name;
	int ACPU,ARAM,AROM;
	Server S;
public:
	Node():S()
	{
		Name="";
		ACPU=2;
		ARAM=16;
		AROM=100;
	}
	Node(string N,int AC,int ARA,int ARO,string SN,int C,int RA,int RO,string dbname,string dbip,string dbuser,string dbpassword)
	:S(SN,C,RA,RO,dbname,dbip,dbuser,dbpassword)
	{
		Name=N;
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
	friend ostream& operator<<(ostream& output, const Node& n)
    {
        output<<"Name: "<<n.Name<<" ";
        output<<"ACPU: "<<n.ACPU<<" ";
        output<<"ARAM: "<<n.ARAM<<" ";
        output<<"AROM: "<<n.AROM<<" ";
        output<<n.S;
        return output;
    }
};

#endif // NODE_HPP_INCLUDED
