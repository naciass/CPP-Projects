#include<iostream>
#include<list>
using namespace std;

enum typ{PLIK,KATALOG};
class DirElement
{
    protected:
    string tekst;
    typ rodzaj;
    public:
    string getS(){return tekst;}
    typ    getR(){return rodzaj;}
};

class File: public DirElement
{
public:
    File(){rodzaj=PLIK;}

};
class Directory: public DirElement
{
private:
    list<DirElement*> lista; // * bo moze byc to folder albo plik
public:
    Directory(){rodzaj=KATALOG;}
    bool add(DirElement* element)
    {
        list<DirElement*>::iterator it;
        for(it=lista.begin(); it!=lista.end(); it++)
        {
            if(element->getS().compare((*it)->getS())==0) return false;

        }
        lista.push_back(element);

    }
    ~Directory()
    {
        list<DirElement*>::iterator it;
        for(it=lista.begin(); it!=lista.end(); it++)
        {
            delete *it;
        }
    }
    bool deletee(const char*name)
    {
        list<DirElement*>::iterator it;
        for(it=lista.begin(); it!=lista.end(); it++)
        {
            if((*it)->getS().compare((*it)->getS())==0)
            {
                lista.erase(it);
                return true;
            }
        }
        return false;
    }
};

