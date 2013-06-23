#include<iostream>
using namespace std;

template <typename T> class Wektor
{
private:
    T *tab;
    int ilosc;
    int ostatni;
    public:
        Wektor(int roz)
        {
            ilosc=roz;
            tab= new T[ilosc];
            ostatni=0;
        }
        ~Wektor
        {
            delete [] tab;
        }
        bool pushback(T&t)
        {
            if(ilosc-ostatni-1 >= 0 )
            {
                tab[ostatni]=t;

            }
            else
            {


              T* ntab=new T[ilosc+1];
               for(int i=0; i<ilosc; i++)
               {
                   ntab[i]=tab[i];
               }

               ntab[i+1]=t;
               ilosc++;
            }
               ostatni++;
        }
        Wektor(const  Wektor<T> &wek )
        {
            ilosc=wek.ilosc;
            ostatni=wek.ostatni;
            tab= new T[ilosc];
            for(int i=0; i<ilosc; i++)
            {
                tab[i]=wek.tab[i];
            }
        }
        T operator [] (int n)
        {
            if(n<=ostatni) return tab[n];
            else
            {
                throw 0;
            }

        }

}
int main()
{
    Wektor fuck(10000);
    try
    {
        fuck[10];
    }
    catch(int cos)
    {
        if(cos==0) cout<<"blad"<<endl;
    }


}
