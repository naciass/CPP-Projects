#include <fstream>
#include <iostream>
using namespace std;


class Iterator
{
    ifstream file;
    string current;
public:
    Iterator(char* filename)
    {
        file.open(filename);
    }
    ~Iterator()
    {
        file.close();
    }
    string get()
    {
        return current;
    }
    void next()
    {
        while(!current.empty())
        {
            if(!file.is_open()||file.eof())
                return;
            getline(file,current);
        }
    }
    bool good()
    {
        if(!file.is_open()||file.eof())
                return false;
        return true;
    }
};
