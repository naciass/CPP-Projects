#include<iostream>
using namespace std;


class MapTexInt
{
private:
struct EL
{
    int liczba;
    char* napis;
    El *nastepny;
}element;
public:
        MapTexInt()
        {
            element=0;
        }
        void add(const char* tekst)
        {
            El *wsk1;
            wsk1=element;
            while(wsk1->nastepny!=0)
            {
                if((wsk1->napis.c_str).compare(tekst.c_str)==0))
                {
                    wsk1->liczba++; return;
                }

                 wsk1=wsk1->nastepny;
            }
              if(wsk1->nastepny==0)
                {


                    wsk1->nastepny=new El;
                    wsk1=wsk1->nastepny;
                    wsk1->liczba=1;
                    wsk1->napis=tekst;

                }



        }

};
