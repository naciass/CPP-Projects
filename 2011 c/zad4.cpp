#include<iostream>
using namespace std;
template<typename T> class Tablica
{
private:
    T** tablica;
    int wiersze;
    int kolumny;
public:
    Tablica(int wiersze, int kolumny)
    {
        this->kolumny=kolumny;
        this->wiersze=wiersze;
        tablica=new T*[wiersze];
        for(int i=0; i<wiersze; i++)
        {
            tablica[i]=new T[kolumny];
        }
    }
    ~Tablica()
    {
        for(int i=0; i<wiersze; i++) //usuwa w kazdym wierszu kolumny
        {

             delete[] tablica[i];
        }
        delete[] tablica;
    }
    T operator()(int wiersz, int kolumna)
    {
            if(wiersz>=wiersze || kolumny>=kolumna) throw 0;
            return tablica[wiersz][kolumna];
    }
     void operator =(const Tablica&tab)
    {   this->~Tablica();
        this->Tablica(tab.wiersze, tab.kolumny);
        for(int i=0; i<tab.wiersze; i++)
        {
            for(int j=0; j<tab.kolumny; j++)
            {
                tablica[i][j]=tab.tablica[i][j];

            }
        }
    }
    Tablica(const Tablica&tab)
    {
        (*this)=tab.tablica;
    }

};
