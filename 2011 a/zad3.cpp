#include<iostream>
#include<list>
using namespace std;
class Book
{
public:
    string author;
    string title;
    string isbn;

};
class Katalog
{
private:
    list<Book> lista;
public:
    void add(const Book &boo)
    {
        list<Book>::iterator it;
        for(it=lista.begin(); it!=lista.end() && it->isbn!=boo.isbn; it++ );
        if(it==lista.end())
        {
            lista.push_back(boo);
        }
        else
        {
            it->author=boo.author;
            it->title=boo.title;
        }
    }
    void findbyAuthor(const char*a, list<Book>&resault)
    {
        list<Book>::iterator it;
        for(it=lista.begin(); it!=lista.end(); it++)
        {
            if(it->author.find(a)!=string::npos)
            {
                resault.push_back(*it);
            }
        }
    }
    void remove(const char*isbn)
    {
        list<Book>::iterator it;
        for(it=lista.begin(); it!=lista.end(); it++)
        {
            if(it->isbn.compare(isbn)==0)
            {
                lista.erase(it);
            }
        }
    }
    Katalog &operator += (const Katalog &other)
    {
        list<Book>::iterator it;
        for(it=other.lista.begin(); it!=other.lista.end(); it++)
        {
            (*this).add(*it);
        }
        return *this;
    }

};
