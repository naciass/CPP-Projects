#include<iostream>
#include<list>
using namespace std;
class Produkt
{
public:
    int id;
    string nazwa;
    string kategoria;
    double cena;
    string opis;
};
class ListaProduktow
{
private:
    list<Produkt> lista;
public:
    void dodajProdukt(const Produkt& pro)
    {
        typename list<Produkt>::iterator it;
        for(it=lista.begin(); it!=lista.end() || it->id==id.pro; it++);
        if(it->id==id.pro)
        {
            it->nazwa=pro.nazwa;

        }
    }

} ;
