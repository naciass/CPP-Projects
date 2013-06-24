#include<iostream>
#include<string>
#include<list>
using namespace std;

class Dictonary
{
private:
    struct para
    {
        list<string> znaczenia;
        string slowo;
    };
    list<para> lista;
public:
    void add(const char*w, const char *m)
    {
        list<para>::iterator it;
        for(it=lista.begin(); it!=lista.end() && it->slowo!=w; it++);
        if(it->slowo.compare(w)!=0)
        {
            para nowa;
            nowa.slowo=w;
            nowa.znaczenia.push_back(m);
            lista.push_back(nowa);
        }
        else
        {
            it->znaczenia.push_back(m);
        }
    }
    void get(const char*w, list<string>&resault)
    {
        list<para>::iterator it;
        list<string>::iterator it2;
        for(it=lista.begin(); it!=lista.end() && it->slowo!=w; it++);
        if(it==lista.end()) return;
        for(it2=it->znaczenia.begin(); it2!=it->znaczenia.end(); it2++)
        {
            resault.push_back(*it2);

        }

    }
    void deletee(const char*w, const char*m)
    {
        list<para>::iterator it;
        list<string>::iterator it2;
        for(it=lista.begin(); it!=lista.end() && it->slowo!=w; it++);
        if(it==lista.end()) return;
        for(it2=it->znaczenia.begin(); it2!=it->znaczenia.end() && it2->compare(m)!=0; it2++);
        if(it2==it->znaczenia.end()) return;
        it->znaczenia.erase(it2);
        if(it->znaczenia.empty()==true) lista.erase(it);
    }
    Dictonary&operator+=(const Dictonary &other)
    {
        list<para>::const_iterator it; //const iterator bo obiekt jest const !!
        list<string>::const_iterator it2;
        for(it=other.lista.begin(); it!=other.lista.end(); it++)
        {
             for(it2=it->znaczenia.begin(); it2!=it->znaczenia.end(); it2++)
             {
                 add(it->slowo.c_str(), (*it2).c_str());
             }

        }
    }
};
