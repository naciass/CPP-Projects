#include<iostream>
#include<map>
using namespace std;

struct miasta
{
    string miasto1;
    string miasto2;
    bool operator < (const miasta &m)
    {
        if(miasto1<m.miasto1)
            return true;
        else
            return false;
    }
};
class SS2D
{
private:
    map<miasta,double> mapa;
public:
    void setAt(const char*first, const char*second, double w)
    {
        map<miasta,double>::iterator it;
        for(it=mapa.begin(); it!=mapa.end(); it++)
        {
            if(it->first.miasto1==first && it->first.miasto2==second)
            {
                it->second=w;
            }
            else
            {
                miasta m;
                m.miasto1=first;
                m.miasto2=second;
                mapa[m]=w;
            }

        }

    }
    double get(const char*first, const char*second )
    {
        map<miasta,double>::iterator it;
        for(it=mapa.begin(); it->first.miasto1!=first && it->first.miasto2!=second && it!=mapa.end(); it++);
        if( it==mapa.end() ) throw 0;
        else
        {
            return it->second;
        }
    }
};
