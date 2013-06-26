class A
{
public:
    ~A(){};
    virtual A* clone() const
    {
        return 0;
    }
};

class B:public A
{
public:
    A* clone() {return new B(*this);}
};
class C:public A
{
public:
    A* clone(){return new C(*this);}
};

class Lista
{
    struct Elem{
        A* val;
        Elem *next;
    }*el;
public:
    Lista()
    {
        el=0;
    }

    ~Lista()
    {
        Elem *wsk=el;
        Elem *wsk2=el;
        while(wsk!=0)
        {
            wsk2=wsk;
            wsk=wsk->next;
            delete wsk2->val;
            delete wsk2;
        }
    }
    void pushFront(const A* a)
    {
        Elem *new1=new Elem;
        new1->val=a->clone();
        new1->next=el;
        el=new1;
    }
    Lista &operator =(const Lista &lst)
    {
        Elem *wsk=lst.el;
        Elem *wsk2=el;
        Elem *wsk3=0;
        while(wsk!=0)
        {
            wsk2=new Elem;
            wsk2->val=wsk->val->clone();
            if(el=0)
            {
                el=wsk2;
                wsk3=el;
            }
            else
                wsk3->next=wsk;
            wsk3=wsk2;
        }
    }
    Lista(const Lista& lst)
    {
        *this=lst;
    }
};
