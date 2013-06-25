#include <list>
#include <iostream>

using namespace std;

class Obiekt{
    virtual wartosc;
    public:
        virtual get(){return wartosc;}
};

class Int: public Obiekt
{
    int wartosc;
};

class Double: public Obiekt
{
    double wartosc;
};

class String: public Obiekt
{
    string wartosc;
};

class Sequence
{
    list<Obiekt*> seq;
public:
    Sequence& operator = (const Sequence &s)
    {
        list<Obiekt*>::const_iterator it;
        Obiekt *nowy;
        for(it=seq.begin(); it!=seq.end();it++)
        {
            typeid
        }
    }
};
