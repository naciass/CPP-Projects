#include <vector>
#include <string>
#include<cstring>
using namespace std;
class Person
{
    string surname, name;
    char pesel[12];
public:
    string getName() const {return name;}
    string getSurname() const {return surname;}
    const char * getPesel() const {return pesel;}
};

class PersonSet
{
    vector<Person> vec;
public:
    void insert(const Person &prs)
    {
        if(!has(prs))
            vec.push_back(prs);
    }
    bool has(const Person &prs) const
    {
        vector<Person>::const_iterator it;
        for(it=vec.begin();it!=vec.end();it++)
        {
            if(it->getSurname().compare(prs.getSurname())==0&&it->getName().compare(prs.getName())==0&&strcmp(prs.getPesel(),it->getPesel())==0)
                return true;
        }
        return false;
    }
    bool operator < (const PersonSet &prs)
    {
        vector<Person>::const_iterator it;
        for(it=vec.begin();it!=vec.end();it++)
        {
            if(!prs.has(*it))
                return false;
        }
        return true;
    }
};
