#include<iostream>
#include<list>
#include<cstdlib>
using namespace std;
class Kontakt
{
public:
    string imie,nazwisko,adres,telefon,email;
};


class ListaKontaktow
{
    private:
    list<Kontakt> lista;
    public:
        void dodajKontakt(const Kontakt&k)
        {
            list<Kontakt>::iterator it;
            for(it=lista.begin(); (it->imie!=k.imie && it->nazwisko!=k.nazwisko) && it!=lista.end(); it++);
            if(it==lista.end() ) lista.push_back(k) ;
            else
            {
                if(!k.email.empty()) it->email=k.email;
                if(!k.adres.empty()) it->adres=k.adres;
                if(!k.telefon.empty()) it->telefon=k.email;

            }

        }
        list<Kontakt> znajdz(const char *txt)
        {
            list<Kontakt> listazw;
            list<Kontakt>::iterator it;
            for(it=lista.begin(); it==lista.end(); it++)
            {
                if(it->imie.find(txt)!=string::npos) listazw.push_back(*it);
                else if (it->nazwisko.find(txt)!=string::npos) listazw.push_back(*it);
                else if (it->email.find(txt)!=string::npos) listazw.push_back(*it);
                else if (it->adres.find(txt)!=string::npos) listazw.push_back(*it);
                else if (it->telefon.find(txt)!=string::npos) listazw.push_back(*it);
            }
            return listazw;
        }
        const char*numer2Nazw(const char*n)
        {
            int numer=atoi(n),i=0; // konwertuje do int
            list<Kontakt>::iterator it;
            for(it=lista.begin(); i<numer && it!=lista.end(); i++, it++);
            if(it==lista.end()) return "";
            else
            {
                string result=it->imie+it->nazwisko;
                return result.c_str();
            }

        }
        void dodaj(const ListaKontaktow &other)
        {
            list<Kontakt>::const_iterator it;
            for(it=other.lista.begin(); it!=other.lista.end(); it++)
            {
                dodajKontakt(*it);
            }
        }
};
int main()
{
    ListaKontaktow ls;
    Kontakt kont;
    kont.imie="Jan";
    kont.nazwisko="Kowalski";
    ls.dodajKontakt(kont);
    cout<<"dzial"<<endl;
}
