#include<iostream>
#include<list>
using namespace std;

struct stringi
{
    string napis1;
    string napis2;
};
class String2String
{
private:
    list<stringi> takieseslowa;
public:
    void add(const char *a, const char *b)
    {
        bool jest=false;
        list<stringi>:: iterator it;
        for(it=takieseslowa.begin(); it!=takieseslowa.end(); it++)
        {
            if((it->napis1).compare(a)==0 && (it->napis2).compare(b)==0) jest=true;
        }
        if(jest==false)
        {
            stringi st;
            st.napis1=a;
            st.napis2=b;
            takieseslowa.push_back(st);
        }
    }
    void removee(const char* a, const char* b)
    {
        list<stringi>:: iterator it;
        for(it=takieseslowa.begin(); it!=takieseslowa.end(); it++)
        {
            if((it->napis1).compare(a)==0 && (it->napis2).compare(b)==0)
            {
                takieseslowa.erase(it);
                return;
            }
        }
    }
    int findd(const char*a, int start)
    {
        int i=1;
        list<stringi>:: iterator it;
        for(it=takieseslowa.begin(); it!=takieseslowa.end() && i<=start; i++, it++);
        if(it==takieseslowa.end()) return -1;
        if(it->napis1.compare(a)==0) return 1;
        else return 0;

    }
    void get(const char *a, String2String &target)
    {
        list<stringi>:: iterator it;
        for(it=takieseslowa.begin(); it!=takieseslowa.end(); it++)
        {
            if(it->napis1.compare(a)==0)
            {
                target.takieseslowa.push_back(*it);

            }
        }
    }
    void operator+=(String2String &ehh)
    {
        list<stringi>:: iterator it;
        for(it=ehh.takieseslowa.begin(); it!=ehh.takieseslowa.end(); it++)
        {
            add(it->napis1.c_str(), it->napis2.c_str());
        }
    }
};
