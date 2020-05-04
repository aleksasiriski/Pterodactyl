#ifndef FILE_HPP_INCLUDED
#define FILE_HPP_INCLUDED
#include <fstream>
void writeFile(string filename,string text,char mode='w')
{
    ofstream file;
    if (mode=='a')
        file.open(filename, ios_base::app);
	else
        file.open(filename);
    file << text << endl;
    file.close();
}
void readFile(string filename)
{
    string line;
    ifstream file(filename);
    if (file.is_open())
    {
        while (getline(file,line))
            cout << line << '\n';
        file.close();
    }
    else
        cout << "Unable to open file.";

}
#endif // FILE_HPP_INCLUDED