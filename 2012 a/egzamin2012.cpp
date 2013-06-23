#include<iostream>
#include<list>
using namespace std;


//Zad2
template<typename N> struct wierzcholek
{
 N element;
 list<wierzcholek<N>* > krawedzie;

};
template<typename N> class Graf
{
private:
    list< wierzcholek < N > > lista;
public:
    //konstruktor
    Graf(){};
    ~Graf(){};
    bool addNode(const N &n)
    {
            for(typename list< wierzcholek < N > >::iterator it=lista.begin(); it!=lista.end(); it++)
            {
                if(it->element==n) return false;

            }
            wierzcholek<N> nowy; // tworzy nowy wierzcholek
            nowy.element=n;
            lista.push_back(nowy); // dodaje na koncu listy ten wierzcholek
            return true;
    }
    bool addEdge(const N &n1,const N&n2)
    {
        typename list< wierzcholek < N > >::iterator it1; //definicja iteratora na zmienna n1
        typename list< wierzcholek < N > >::iterator it2; // definicja iteratora na zmienna n2

        for(it1=lista.begin(); it1->element!=n1 && it1!=lista.end(); it1++); // robimy to po to aby miec wskaznik na wierzcholek z n1
        for(it2=lista.begin(); it2->element!=n2 && it2!=lista.end(); it2++);
        if(it1==lista.end() || it2==lista.end()) return false;
        it1->krawedzie.push_back(&(*it2));
        return true;
    }
    void getNeighbours(const N&n, list<N>&result)
    {
        typename list<N>::iterator itsz;
        for (itsz=lista.begin(); itsz->element!=n && itsz!=lista.end(); itsz++);
        if(itsz==lista.end() ) return;
        for(typename list<wierzcholek<N>*>::iterator it=itsz->krawedzie.begin(); it!=itsz->krawedzie.end(); it++ )
        {
            result.push_back(*it->element);
        }

    }


};
int main()
{
    Graf<int> gr;
    gr.addNode(1);
    gr.addNode(2);
    gr.addEdge(1,2);
    return 0;

}
