#ifndef LOCATION_HPP_INCLUDED
#define LOCATION_HPP_INCLUDED
#include "node.hpp"
class Location
{
private:
	string CC;
	vector<Node*> nodes;
public:
	Location(string CC)
	{
		this->CC=CC;
	}
	~Location()
	{
		for(auto i=nodes.begin();i!=nodes.end();i++)
			delete *i;
	}
	void setCC(string CC)
	{
		this->CC=CC;
	}
	string getCC()const
	{
		return CC;
	}
	Node* getNode()const
	{
		ListNodes();
		cout << "\t >>> ";
		int choice;
		cin >> choice;
		choice--;
		return *(nodes.begin()+choice);
	}
	void AddNode()
	{
		int AC,ARA,ARO,C,RA,RO;
		string Name,SName,dbname,dbip,dbuser,dbpassword;
		cout << "\tNode name >>> ";
		cin >> Name;
		cout << "\tAvailable CPU >>> ";
		cin >> AC;
		cout << "\tAvailable RAM >>> ";
		cin >> ARA;
		cout << "\tAvailable ROM >>> ";
		cin >> ARO;
		cout << "\tServer name >>> ";
		cin >> SName;
		cout << "\tServer CPU >>> ";
		cin >> C;
		cout << "\tServer RAM >>> ";
		cin >> RA;
		cout << "\tServer ROM >>> ";
		cin >> RO;
		cout << "\tDatabase name >>> ";
		cin >> dbname;
		cout << "\tDatabase IP >>> ";
		cin >> dbip;
		cout << "\tDatabase user >>> ";
		cin >> dbuser;
		cout << "\tDatabase password >>> ";
		cin >> dbpassword;
		Node* n=new Node(Name,AC,ARA,ARO,SName,C,RA,RO,dbname,dbip,dbuser,dbpassword);
		nodes.push_back(n);
	}
	void ListNodes()const
	{
		if(nodes.empty())
        {
            cout << "Nodes do not exist.\n";
            return;
        }
		int counter=1;
		for(auto i=nodes.begin();i!=nodes.end();i++)
			cout << counter++ << ") " << **i << endl;
	}
	void DeleteNode()
	{
		cout << "\t----- Select node to delete -----\n";
		ListNodes();
		if(nodes.empty())
            return;
		cout << "\t >>> ";
		int choice;
		cin >> choice;
		choice--;
		delete *(nodes.begin()+choice);
		nodes.erase(nodes.begin()+choice);
	}
	friend ostream& operator<<(ostream& output, const Location& l)
    {
        output<<l.CC<<endl;
        return output;
    }
};

#endif // LOCATION_HPP_INCLUDED
