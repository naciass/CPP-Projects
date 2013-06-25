#include<iostream>
#include<list>
using namespace std;

class Miasto
{
public:
    string name;
    int population;

};
bool compare( const Miasto &m1, const Miasto &m2)
{
    if(m1.population<m2.population) return true;
    else return false;
}
class Iterator
{
private:
    list<Miasto> lista;
    list<Miasto>::iterator it;
public:
    Iterator(const list<Miasto> &mias)
    {
        lista=mias;
        lista.sort(compare);
    }
    bool operator()()
    {
        if(it==lista.end()) return false;
        else return true;
    }
   void operator++()
   {
       it++;
   }
   Miasto* get()
   {
       return (&(*it));
   }
};
