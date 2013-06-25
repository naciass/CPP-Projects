#include<iostream>
#include<fstream>
using namespace std;

class Iterator
{
private:
    ifstream plik;
    string  slowo;
public:
    Iterator(const char* nazwa)
    {
        plik.open(nazwa);
        nextWord();
    }
    bool havemorewords()
    {
        if(plik.is_open() || !plik.eof() )
        {
            return true;
        }
        return false;
    }
    void nextWord()
    {
        if(plik.is_open() || !plik.eof())
        {
            plik>>slowo;
        }

    }
    const char* get()
    {
        return slowo.c_str();
    }

};
