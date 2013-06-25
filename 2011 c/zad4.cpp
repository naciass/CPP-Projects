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

}
