#include<iostream>
#include<vector>
using namespace std;

template <typename V> class Matrix
{
private:
    vector<vector<N>> tablica;
    int ilosc;
public:
    Matrix();
    ~Matrix()
    {
        (*this).clear;
    }
    void get(int row, int col, V &val )
    {

       val=tablica[row][col]
    }

};
