#ifndef PANEL_HPP_INCLUDED
#define PANEL_HPP_INCLUDED
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
#include "location.hpp"
#include "eggnestpack.hpp"
#include "user.hpp"
const char clear[]="clear"; //UNIX
//const char clear[]="cls"; //Windows
bool toexit(string choice)
{
    if( 
        
        choice=="q"||choice=="quit"||
        choice=="e"||choice=="exit"||
        choice=="s"||choice=="stop"
        
        )return true;
    else return false;
}
class Panel
{
private:
    vector<User*> users;
    vector<Admin*> admins;
    string userfile,adminfile;
public:
    Panel(string userfile="users.txt",string adminfile="admins.txt")
    {
        this->userfile=userfile;
        this->adminfile=adminfile;
        loadUsers();
        if(loadAdmins())
            Admin::setGlobalID((*(admins.rbegin()))->getadminID());
    }
    void loadUsers()
    {
        ifstream file(userfile);
        if (file.is_open())
        {
            string FName,LName,Username,Email,Password;
            while(!file.eof())
            {
                file>>FName>>LName>>Username>>Email>>Password;
                if(file.eof()) break;
                User* u=new User(FName,LName,Username,Email,Password);
                users.push_back(u);
            }
            file.close();
        }
        else
        {
            cout << "Unable to open file. Creating " << userfile << endl;
            saveUsers();
        }
    }
    void listUsers()const
    {
        int counter=1;
        for(auto i=users.begin();i!=users.end();i++)
            cout<<"\t"<<counter++<<") "<<**i<<endl;
    }
    void saveUsers()const
    {
        ofstream file(userfile);
        for(auto i=users.begin();i!=users.end();i++)
        {
            file<<(*i)->getFName()<<" ";
            file<<(*i)->getLName()<<" ";
            file<<(*i)->getUsername()<<" ";
            file<<(*i)->getEmail()<<" ";
            file<<(*i)->getPassword()<<endl;
        }
        file.close();
    }
    bool loadAdmins()
    {
        ifstream file(adminfile);
        if (file.is_open())
        {
            string FName,LName,Username,Email,Password;
            unsigned short adminID;
            bool prazan=true;
            while(!file.eof())
            {
                file>>FName>>LName>>Username>>Email>>Password>>adminID;
                if(file.eof()) break;
                Admin* a=new Admin(FName,LName,Username,Email,Password,adminID);
                admins.push_back(a);
                prazan=false;
            }
            file.close();
            if(prazan) return false;
            return true;
        }
        else
        {
            cout << "Unable to open file. Creating " << adminfile << endl;
            saveAdmins();
            return false;
        }
    }
    void listAdmins()const
    {
        for(auto i=admins.begin();i!=admins.end();i++)
            cout<<"\t"<<**i<<endl;
    }
    void saveAdmins()const
    {
        ofstream file(adminfile);
        for(auto i=admins.begin();i!=admins.end();i++)
        {
            file<<(*i)->getFName()<<" ";
            file<<(*i)->getLName()<<" ";
            file<<(*i)->getUsername()<<" ";
            file<<(*i)->getEmail()<<" ";
            file<<(*i)->getPassword()<<" ";
            file<<(*i)->getadminID()<<endl;
        }
        file.close();
    }
    void create(User* u)
    {
        u->setup();
        if(u->isadmin())
            admins.push_back((Admin*)u);
        else
            users.push_back(u);
    }



    void SaveChanges()
    {
        system(clear);
        cout << "Saving changes...\n";
        saveUsers();
        saveAdmins();
        cout << "Changes succesfully saved. Bye!\n";
    }
    void CreateUser()
    {
        char type;
        system(clear);
        cout << "----- User creation -----\n";
        while(1)
        {
            cout << "\tIs this normal user or admin?\n";
            cout << "\t u/a >>> ";
            cin >> type;
            if(type=='u' || type=='a')
                break;
            cout << "\tIncorrect input! Try again.\n";
        }
        if(type=='u'){User* u=new User;create(u);}
        else{Admin* a=new Admin;create(a);}
    }
    void ListUsers()const
    {while(1){
        system(clear);
        cout << "------------------------- Users -------------------------\n\n";
        listUsers();
        cout << "------------------------- Admins ------------------------\n\n";
        listAdmins();
        char done;
        cout << "Done? (y) ";
        cin >> done; 
        if(done=='y')
            break;
    }}
    void SearchFName()
    {while(1){
        system(clear);
        cout << "\tSearch for >>> ";
        string sFName;
        cin >> sFName;
        cout << "\t----- Users with same first name -----\n";
        for(auto i=users.begin();i!=users.end();i++)
        {
            if(((*i)->getFName())==sFName)
                cout<<"\t"<<**i;
        }
        cout << "\t----- Admins with same first name -----\n";
        for(auto i=admins.begin();i!=admins.end();i++)
        {
            if(((*i)->getFName())==sFName)
                cout<<"\t"<<**i;
        }
        cout << "Done? (y) ";
        char done;
        cin >> done;
        if(done=='y')
            break;
    }}
    void SearchLName()
    {while(1){
        system(clear);
        cout << "\tSearch for >>> ";
        string sLName;
        cin >> sLName;
        cout << "\t----- Users with same last name -----\n";
        for(auto i=users.begin();i!=users.end();i++)
        {
            if(((*i)->getLName())==sLName)
                cout<<"\t"<<**i;
        }
        cout << "\t----- Admins with same last name -----\n";
        for(auto i=admins.begin();i!=admins.end();i++)
        {
            if(((*i)->getLName())==sLName)
                cout<<"\t"<<**i;
        }
        cout << "Done? (y) ";
        char done;
        cin >> done;
        if(done=='y')
            break;
    }}
    void SearchUsername()
    {while(1){
        system(clear);
        cout << "\tSearch for >>> ";
        string sUsername;
        cin >> sUsername;
        cout << "\t----- Users with same username -----\n";
        for(auto i=users.begin();i!=users.end();i++)
        {
            if(((*i)->getUsername())==sUsername)
                cout<<"\t"<<**i;
        }
        cout << "\t----- Admins with same username -----\n";
        for(auto i=admins.begin();i!=admins.end();i++)
        {
            if(((*i)->getUsername())==sUsername)
                cout<<"\t"<<**i;
        }
        cout << "Done? (y) ";
        char done;
        cin >> done;
        if(done=='y')
            break;
    }}
    void SearchEmail()
    {while(1){
        system(clear);
        cout << "\tSearch for >>> ";
        string sEmail;
        cin >> sEmail;
        cout << "\t----- Users with same email -----\n";
        for(auto i=users.begin();i!=users.end();i++)
        {
            if(((*i)->getEmail())==sEmail)
                cout<<"\t"<<**i;
        }
        cout << "\t----- Admins with same email -----\n";
        for(auto i=admins.begin();i!=admins.end();i++)
        {
            if(((*i)->getEmail())==sEmail)
                cout<<"\t"<<**i;
        }
        cout << "Done? (y) ";
        char done;
        cin >> done;
        if(done=='y')
            break;
    }}
    void SearchUsers()
    {while(1){
        string choice;
        cout << "\t----- Search users -----\n";
        cout << "\t1) By first name\n\t2) By last name\n\t3) By username\n\t4) By email\n";
        cout << "\tq) Stop searching\n";
        cout << "\t >>> ";
        cin >> choice;
        if(toexit(choice))
            break;
        char choicec=choice[0];
        switch(choicec)
        {
            case '1': SearchFName(); break;
            case '2': SearchLName(); break;
            case '3': SearchUsername(); break;
            case '4': SearchEmail(); break;
        }
    }}
    void DeleteUsers()
    {while(1){
        string choice;
        cout << "\t----- Delete users -----\n";
        cout << "\td) Delete user\n";
        cout << "\tq) Exit deleting\n";
        cout << "\t >>> ";
        cin >> choice;
        if(toexit(choice))
            break;
        system(clear);
        cout << "\t----- Enter user info -----\n";
        cout << "\t     FName LName Username Email\n";
        cout << "\t >>> ";
        string FName,LName,Username,Email;
        cin >> FName >> LName >> Username >> Email;
        system(clear);
        cout << "Searching for user...\n";
        bool deleted=false;
        for(auto i=users.begin();i!=users.end();i++)
        {
            if((*i)->getFName()==FName){
                if((*i)->getLName()==LName){
                    if((*i)->getUsername()==Username){
                        if((*i)->getEmail()==Email){
                            deleted=true;
                            users.erase(i);
                        }}}}
            if(deleted)
                break;
        }
        if(deleted)
            cout << "Succesfully deleted user!\n\n";
        else
            cout << "Failed to delete user, not found.\n\n";
    }}
    void ChangeUsers()
    {while(1){
        string choice;
        cout << "\t----- Change users -----\n";
        cout << "\tc) Change user\n";
        cout << "\tq) Exit changing\n";
        cout << "\t >>> ";
        cin >> choice;
        if(toexit(choice))
            break;
        system(clear);
        cout << "\t ----- Choose user to change -----\n";
        listUsers();
        cout << "\t >>> ";
        int ichoice;
        cin >> ichoice;
        ichoice--;
        while(1){
        system(clear);
        cout << "\t ----- Changing user... -----\n";
        auto i=users.begin()+ichoice;
        cout << **i;
        cout << "\t ----- Choose what to change -----\n";
        cout << "\t1) FName\n\t2) LName\n\t3) Email\n\t4) Password\n\te) Exit\n";
        cout << "\t >>> ";
        cin >> choice;
        if(toexit(choice))
            break;
        char cchoice='4';
        if(choice=="1")
            cchoice='1';
        else if(choice=="2")
            cchoice='2';
        else if(choice=="3")
            cchoice='3';
        switch(cchoice)
        {
            case '1':
            {
                string NFName;
                cout << "\tNew first name: ";
                cin >> NFName;
                (*i)->setFName(NFName);
                break;
            }
            case '2':
            {
                string NLName;
                cout << "\tNew last name: ";
                cin >> NLName;
                (*i)->setLName(NLName);
                break;
            }
            case '3':
            {
                string NEmail;
                cout << "\tNew Email address: ";
                cin >> NEmail;
                (*i)->setEmail(NEmail);
                break;
            }
            case '4':
            {
                char tchoice;
                cout << "\tr) Random password\n\tc) Change password\n";
                cout << "\t >>> ";
                cin >> tchoice;
                if(tchoice=='r')
                    (*i)->resetPassword();
                else
                    (*i)->changePassword();
                break;
            }
        }
    }}}
};
#endif //PANEL_HPP_INCLUDED