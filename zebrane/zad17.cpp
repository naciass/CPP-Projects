#include<iostream>
using namespace std;


class Iterator
{
private:
    ifstream plik;
    char c;
public:
    Iterator(const char* nazwa)
    {
        plik.open(nazwa);
        next();
    }
    void next()
    {
        char d;
        if(plik.is_open() || !plik.eof())
        {
            d=plik.get();
            if(isalnum(d)) c=d;
            else c=' ';
        }
    }
    char get()
    {
        return c;
    }
    bool good()
    {
        if(plik.is_open() || !plik.eof())
        {
            return true;
        }
        return false;
    }
    ~Iterator()
    {
        plik.close();
    }



};
