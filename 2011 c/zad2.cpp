#include <list>
#include <iostream>

using namespace std;
enum Typ{INT, DOUBLE, STRING};
class Obiekt{
    public:
        virtual Typ getType()=0;
        virtual void *get()=0;
        virtual void set(void * v);
};

class Int: public Obiekt
{
    int wartosc;
public:
    Typ getType(){return INT;};
    void *get(){return &wartosc;}
    void set(void *v){wartosc=*reinterpret_cast<int*>(v);}
};

class Double: public Obiekt
{
    double wartosc;
public:
    Typ getType(){return DOUBLE;}
    void *get(){return &wartosc;}
    void set(void *v){wartosc=*reinterpret_cast<double*>(v);}
};

class String: public Obiekt
{
    string wartosc;
public:
    Typ getType(){return STRING;};
    void *get(){return &wartosc;}
    void set(void *v){wartosc=*reinterpret_cast<string*>(v);}
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
            switch((*it)->getType())
            {
                case INT: nowy=new Int;nowy->set((*it)->get()); break;
                case DOUBLE: nowy=new Double;nowy->set((*it)->get()); break;
                case STRING: nowy=new String;nowy->set((*it)->get()); break;
            }
        }
    }
};
