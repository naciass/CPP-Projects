#include<iostream>
#include<cmath>
using namespace std;

class Command
{
protected:
    int x,y;
    int r;
    bool czyRysowac;
public:
   void virtual wykonaj(int pozycja)=0;

} ;
class Move : virtual public Command
{
public:
void wykonaj(int distance)
{
    x+=distance*cos(r);
    y+=distance*sin(r);
}
};
class Turn : virtual public Command
{
public:
    void wykonaj(int turn)
    {
        r+=turn;
    }

};
class PutPen : virtual public Command
{
    virtual bool
};
