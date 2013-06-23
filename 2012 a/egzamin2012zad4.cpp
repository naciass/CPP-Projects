#include<iostream>
#include<cstring>
using namespace std;

class Dictonary
{
    private:
    char** tekst;
    char** tekst2;
    int ilosc;
    public:
        Dictonary():ilosc(0) {}
        ~Dictonary()
        {
            for(int i=0; i<ilosc; i++)
            {
                delete[] tekst[i];
                delete[] tekst2[i];
            }
            delete[] tekst;
            delete[] tekst2;

        }
        bool setAt(const char*key, const char*value)
        {
                for(int i=0; i<ilosc; i++)
                {
                    if(strcmp(key,tekst[i])==0)
                    {
                        delete[] tekst2[i];
                        tekst2[i]=new char[strlen(value)];
                        strcpy(tekst2[i],value);
                        return true;
                    }
                }
                char** tmp1=new char*[ilosc+1];
                char** tmp2=new char*[ilosc+1];
                for(int i=0; i<ilosc; i++)
                {
                    tmp1[i]=tekst[i];
                    tmp2[i]=tekst2[i];
                }
                tmp1[ilosc]=new char[strlen(key)];
                strcpy(tmp1[ilosc], key);
                tmp2[ilosc]=new char[strlen(value)];
                strcpy(tmp2[ilosc], value);
                delete [] tekst;
                delete [] tekst2;
                tekst=tmp1;
                tekst2=tmp2;
                ilosc++;
                return true;
        }
        void operator = (Dictonary &dic)
        {
            cout<<dic.tekst[0]<<endl;
            tekst=new char*[dic.ilosc];
            tekst2=new char*[dic.ilosc];
            ilosc=dic.ilosc;
            for(int i=0; i<ilosc; i++)
            {
                tekst[i]=new char[strlen(dic.tekst[i])];
                tekst2[i]=new char[strlen(dic.tekst2[i])];
                strcpy(tekst[i],dic.tekst[i]);
                strcpy(tekst2[i], dic.tekst2[i]);
            }
        }
        Dictonary(Dictonary &dic)
        {
            *this=dic;
        }


};
int main()
{
    Dictonary dic, nary;
    dic.setAt("adam", "swiezowski");
    cout<<"A"<<endl;
    nary=dic;
    cout<<"B"<<endl;
    return 0;
}
