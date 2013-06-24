#include<iostream>
using namespace std;
//zaczynamy!
template<typename T> class Lista
{
private:
    struct El
    {
        El*nastepny;
        T wartosc;
        El*poprzedni;
    }*element;
public:

        Lista()
        {
            element=0;
        }
        ~Lista()
        {
            El *wsk1,*wsk2;
            wsk1=element;
            while(wsk1!=0)
            {
                wsk2=wsk1;
                wsk1=wsk1->nastepny;
                delete wsk2;
            }
        }
        bool pushBack(const T&t)
        {
            El *wsk1, *wsk2;
            El *nowy=new El; // jest tutaj * bo tworze w funkcji i by mi sie pipa usunela
            wsk1=element;
            if(wsk1==0)
            {
                El *nowy=new El;
                element=nowy;
                nowy->poprzedni=0;
                nowy->nastepny=0;
                nowy->wartosc=t;
            }
            else
        {


            while(wsk1->nastepny!=0)
            {
                wsk1=wsk1->nastepny;
            }
            wsk1->nastepny=nowy;
            nowy->poprzedni=wsk1;
            nowy->wartosc=t;
            nowy->nastepny=0;
        }

    }
    void operator =(Lista &lis)
    {
        El *wsk1, *wsk2;
        wsk1=lis.element;
        while(wsk1!=0)
        {
            El *nowy=new El;
            pushBack(wsk1->wartosc);
            wsk1=wsk1->nastepny;
        }
    }
    Lista(Lista &lis)
    {
        (*this)=lis;
    }

};
