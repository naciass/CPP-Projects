#include <vector>
#include<string>
#include<typeinfo>
using namespace std;


class Obiekt{
public:
    virtual ~Obiekt();//żeby usuwały się obiekty pochodne
};


class Int:public Obiekt{
public:
	int value;
	Int(int v=0):value(v){}
 };

 class Double:public Obiekt{
 public:
	double value;
	Double(double v=0):value(v){}
 };

 class String:public Obiekt{
 public:
	string value;
	String(string v=""):value(v){}
 };

 class Sequence: public vector<Obiekt *>
 {
 protected:
	 Obiekt *cloneObiekt (const Obiekt *obj)
	 {
		if(typeid(*obj)==typeid(Int))
			return new Int(*static_cast<const Int*>(obj));
		if(typeid(*obj)==typeid(Double))
			return new Double(*static_cast<const Double*>(obj));
		if(typeid(*obj)==typeid(String))
			return new String(*static_cast<const String*>(obj));
	 }
 public:
	Sequence(){};
	Sequence &operator =(const Sequence &seq)
	{
		const_iterator it;
		for(it=seq.begin(); it!=seq.end();it++)
		{
			push_back(cloneObiekt(*it));
		}
	}
	Sequence(const Sequence &seq)
	 {
		 *this=seq;
	 }
	 ~Sequence()
	 {
		iterator it;
		 for(it=begin(); it!=end();it++)
		 {
			delete *it;
		 }
	 }
 };
