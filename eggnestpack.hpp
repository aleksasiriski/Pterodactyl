#ifndef EGGNESTPACK_HPP_INCLUDED
#define EGGNESTPACK_HPP_INCLUDED
class Egg //egg je skup komandi za instalaciju odredjenog server (vrsta igre i verzija)
{
protected:
	string name,desc;
public:
	Egg()
	{
		name="";
		desc="";
	}
	Egg(string n,string d)
	{
		name=n;
		desc=d;
	}
};
class Pack:public Egg //pack je egg samo ne fabricki vec koji admin doda za ceo panel, ima svoju verziju i vidljivost obicnim userima
{
private:
	string version;
	bool visible;
public:
	Pack()
	{
		Egg::name="";
		Egg::desc="";
		version="";
		visible=false;
	}
	Pack(string n,string d,string ver,bool v)
	{
		Egg::name=n;
		Egg::desc=d;
		version=ver;
		visible=v;
	}
};
class Nest //nest je skup eggova, samo fabrickih eggova
{
private:
	string name,desc;
	Egg e;
public:
	Nest():e()
	{
		name="";
		desc="";
	}
	Nest(string n,string d,string en,string ed):e(en,ed)
	{
		name=n;
		desc=d;
	}
};

#endif // EGGNESTPACK_HPP_INCLUDED
