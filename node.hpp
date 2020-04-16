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
	}
	Node(int AC,int ARA,int ARO)
	{
		ACPU=AC;
		ARAM=ARA;
		AROM=ARO;
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