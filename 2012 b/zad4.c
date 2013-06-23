#include<iostream>
using namespace std;

class A
{
private:
    string dupa;
public:
    ~A();

};
class B :public A
{
private:
    string kupa;


};
class C :public A
{
private:
    string fuferko;
};
class Lista
{
    private;
    struct El
    {
    A* klasa;
    El *nastepny;
    }
    *element; // tworze wskaŸnik do elementu bo jego sie nie usuwa
    public:
        Lista()
        {
            element=0;
        }
        ~Lista()
        {
            El *wsk,*wsk1;
            wsk=element;
            while(wsk!=0)
            {
                wsk1=wsk;
                wsk=wsk->nastepny;
                delete wsk1->klasa;
                delete wsk1;

            }
        }
        void pushFront(const A*a)
        {
            El *nowy=new El;
            nowy->klasa=a;
            nowy->nastepny=element;
            element=nowy;
        }
        void operator =(Lista &lis)
        {
            El *wsk,*wsk1;
            wsk=element; // ten do którego jest kopiowany
            wsk1=lis.element; // z niego sie kopiuje
            while(wsk1!=0)
            {
                if(element==0)
                {
                    wsk=new El;  // element pierwszy

                }
                else
                {
                    wsk->nastepny=new El;
                    wsk=wsk->nastepny;

                }
                wsk->klasa=wsk1->klasa;
                wsk1=wsk1->nastepny;
                wsk->nastepny=0; // ¿eby sie skonczyla lista

            }

            Lista(Lista &lis)
            {
                (*this)=lis;
            }


        }
};
