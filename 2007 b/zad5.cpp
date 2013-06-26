#include<iostream>
#include <vector>
using namespace std;

class Zwierzeta
{
public:
    virtual Zwierzeta* clone()=0;
};
class Pies: public Zwierzeta
{
public:
    Zwierzeta* clone()
    {
        return new Pies(*this);
    }
};
class Kot: public Zwierzeta
{
public:
    Zwierzeta* clone()
    {
        return new Kot(*this);
    }
};
class Koza: public Zwierzeta
{
public:
    Zwierzeta* clone()
    {
        return new Koza(*this);
    }
};

void copy(vector<Zwierzeta *>&target,const vector<Zwierzeta*> &src)
{
    vector<Zwierzeta*>::const_iterator it;
    for(it=src.begin();it!=src.end();it++)
    {
        target.push_back((*it)->clone());
    }
}
