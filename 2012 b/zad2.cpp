#include<iostream>
#include<vector>
using namespace std;

template <typename V> class Matrix
{
private:
    vector<vector<V> > tablica;

public:
    Matrix();
    ~Matrix()
    {
        (*this).clear;
    }
    void get(int row, int col, V &val )
    {

       val=tablica[row][col];
    }
    void set(int row, int col, V &val)
    {
        tablica[row][col]=val;
    }
    int getRowcount()
    {
        return tablica.size();


    }
    int getColcount()
    {
        return tablica[i].size();
    }

};
