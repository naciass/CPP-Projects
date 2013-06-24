#include <iostream>
#include <list>
#include <cmath>

using namespace std;
enum Type {MOVE, TURN, PUTPEN,NONE};

class Command
{
public:
	virtual void wykonaj()=0;
	virtual Type typ(){return NONE;}
	int x,y,turn;
    bool down;
};

class Move: public Command
{
    int x,y;
public:

	Move(int _x, int _y)
	{
		x=_x;y=_y;
	}
	void wykonaj()
	{
		Command::x+=x*cos(Command::turn);
		Command::y+=y*sin(Command::turn);
	}
	Type typ(){return MOVE;}
};

class Turn: public Command
{
	int turn;
public:
	Turn(int t)
	{
		turn=t;
	}
	void wykonaj()
	{
		Command::turn+=turn;
	}
	Type typ(){return TURN;}
};

class PutPen : public Command
{
	bool down;
public:
	PutPen(bool down)
	{
		this->down=down;
	}
	void wykonaj()
	{
		Command::down=down;
	}
	Type typ(){return PUTPEN;}
};

class ProgramLogo
{
protected:
	int x,y,turn;
	bool down;
private:
	list<Command*> polecenia;
public:
	ProgramLogo(int x=0, int y=0, int turn=0, bool down=true)
	{
		this->x=x; this->y=y;this->turn=turn; this->down=down;
	}
	ProgramLogo& operator = (const ProgramLogo &p)
	{
		x=p.x; y=p.y; turn=p.turn; down=p.down;
		list<Command*>::const_iterator it;
		Command *nowy;
		for(it=p.polecenia.begin();it!= p.polecenia.end();it++)
		{

			switch((*it)->typ())
			{
			   // /home/swiezy/Dokumenty/szkoła/agh/JIMP 2/CPP-Projects/2011 a/zad2.cpp|86|error: cannot dynamic_cast ‘it.std::_List_iterator<_Tp>::operator*<Command*>()’ (of type ‘class Command*’) to type ‘class Move’ (target is not pointer or reference)|
				case MOVE:nowy = new Move(*dynamic_cast<const Move*>(*it)); break;
				case TURN:nowy = new Turn(*dynamic_cast<const Turn*>(*it)); break;
				case PUTPEN:nowy = new PutPen(*dynamic_cast<const PutPen*>(*it)); break;
			}
			polecenia.push_back(nowy);
		}
	}
	ProgramLogo(ProgramLogo &p)
	{
		*this=p;
	}
	~ProgramLogo()
	{
		list<Command*>::iterator it;
		for(it=polecenia.begin();it!= polecenia.end();it++)
		{
			delete *it;
		}
	}
	void newCommand(Command *c)
	{
		polecenia.push_back(c);
	}
	void wykonaj()
	{
	    list<Command*>::iterator it;
	    for(it=polecenia.begin(); it!= polecenia.end();it++)
        {
            (*it)->wykonaj();
            x=(*it)->x;y=(*it)->y;turn=(*it)->turn;down=(*it)->down;
            polecenia.erase(it);
        }
	}
};



