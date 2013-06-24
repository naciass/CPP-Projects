#include<list>
#include<string>
using namespace std;

enum Typ{PLIK, FOLDER};

class File
{
protected:
    string nazwa;
    Typ typ;
public:
    File(string n="nowy plik")
    {
        nazwa=n;
        typ=PLIK;
    }
    Typ getType(){return typ;}
    string getName(){return nazwa;}
};

class Folder: public File
{
    list<File*> files;
public:
    Folder(string n="nowy folder"): File(n)
    {
        typ=FOLDER;
    }
    ~Folder()
    {
        list<File*>::iterator it;
        for(it=files.begin();it!=files.end();it++)
        {
            delete *it;
        }
    }
    Folder& operator =(const Folder &f)
    {
        list<File*>::const_iterator it;
        File *nowy;
        for(it=f.files.begin();it!=f.files.end();it++)
        {
            if((*it)->getType()==PLIK)
                nowy=new File((*it)->getName());
            else
                nowy=new Folder((*it)->getName());
        }
    }
    Folder(const File &f)
    {
        *this=f;
    }
};
