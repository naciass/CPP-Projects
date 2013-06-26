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
    ListaProduktow(){}
    void dodajProdukt(const Produkt& pro)
    {
        list<Produkt>::iterator it;
        for(it=lista.begin(); it!=lista.end() && it->id!=pro.id; it++);
        if(it->id==pro.id)
        {
            it->nazwa=pro.nazwa;
            it->kategoria=pro.kategoria;
            it->opis=pro.opis;
            it->cena=pro.cena;
        }
        if(it==lista.end()) lista.push_back((*it));
    }
    list<int> znajdzProdukty(const char*txt)
    {
        list<int> znalezione;
        list<Produkt>::iterator it;
        for(it=lista.begin(); it!=lista.end(); it++)
        {
            if
        }
    }
};
