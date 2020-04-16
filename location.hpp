#ifndef LOCATION_HPP_INCLUDED
#define LOCATION_HPP_INCLUDED
#include "node.hpp"

class Location()
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
};

#endif // LOCATION_HPP_INCLUDED