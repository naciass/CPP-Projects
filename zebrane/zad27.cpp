#include<iostream>
#include<list>
using namespace std;

class Graf
{
private:
    struct krawedz
    {
        int start;
        int koniec;

    };
    list<int> wierzcholki;
    list<krawedz> krawedzie;
    int ilosc;
public:
    Graf(int n)
    {
        for(int i=0; i<n; i++)
        {
            wierzcholki.push_back(i);
        }
        ilosc=n;
    }
    void dodajKrawedz(int st, int kn)
    {
        if(!(kn<ilosc && st<ilosc)) return;
        list<krawedz>::iterator it;
        for(it=krawedzie.begin(); it!=krawedzie.end(); it++)
        {
            if(it->start==st && it->koniec==kn) return;

        }
        krawedz kr;
        kr.start=st-1;
        kr.koniec=kn-1;
        krawedzie.push_back(kr);


    }
    bool operator <(const Graf &gr)
    {
        list<krawedz>::const_iterator it, it2;

            for(it=krawedzie.begin(); it!=krawedzie.end(); it++)
            {
                bool czyjest=false;
                for(it2=gr.krawedzie.begin();it2!=gr.krawedzie.end();it2++)
                    if(it->start==it2->start && it->koniec==it2->koniec) czyjest=true;
                if(czyjest==false) return false;
            }
            return true;

    }
    bool jestDroga(int pcz, int kon)
    {
        if(!(kon<ilosc && pcz<ilosc)) return false;
        list<krawedz>::iterator it;
        for(it=krawedzie.begin(); it!=krawedzie.end(); it++)
        {
            if(it->start==pcz && it->koniec==kon) return true;
        }
        return false;
    }
};
