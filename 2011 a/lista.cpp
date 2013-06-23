#include<iostream>
using namespace std;
class Lista
{
 private:
struct El
{
    int adamwalsiebomniezostawiles;
    El  *nastepny;
};
El *element;
public:
void dodajnapoczatku(int liczba)
{
    El *wsk, *wsk1;
    wsk=new El;
    wsk->nastepny=element;
    element=wsk;
    wsk->adamwalsiebomniezostawiles=liczba;

}
El()
{
    element=0;
}
~El()
{
    El *wsk,*wsk1;
    wsk=element;
    while(wsk!=0)
    {
        wsk1=wsk->nastepny;
        delete wsk;
        wsk=wsk1;
    }
}
};
