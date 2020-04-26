#ifndef EGGNESTPACK_HPP_INCLUDED
#define EGGNESTPACK_HPP_INCLUDED

class Egg
{
protected:
	string name,desc;
public:
}
class Nest
{
private:
	string name,desc;
	Egg e1,e2,e3;
public:
}
class Pack:public Egg
{
private:
	string version;
	bool visible;
public:
}

#endif // EGGNESTPACK_HPP_INCLUDED