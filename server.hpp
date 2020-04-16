#ifndef SERVER_HPP_INCLUDED
#define SERVER_HPP_INCLUDED
#include "database.hpp"
class Server()
{
private:
	int CPU,RAM,ROM;
	database DB;
public:
	Server()
	{
		CPU=1;
		RAM=2;
		ROM=5;
	}
	Server(int C,int RA,int RO)
	{
		CPU=C;
		RAM=RA;
		ROM=RO;
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
	int setRAM(int RA)
	{
		RAM=RA;
	}
	int getROM()const
	{
		return ROM;
	}
	int setROM(int RO)
	{
		ROM=RO;
	}
};

#endif // SERVER_HPP_INCLUDED