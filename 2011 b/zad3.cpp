#include<iosteream>
#include<string>
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
            lista.push_back(w);
            it->znaczenia.push_back(m);
        }
        else
        {
            it->znaczenia.push_back(m);
        }
    }
    void get(const char*w, list<string>&resault)
};
