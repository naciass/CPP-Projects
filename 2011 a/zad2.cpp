#include <iostream>
using namespace std;

enum Type {MOVE, TURN, PUTPEN};

class ProgramLogo;

class Command, public ProgramLogo
{
public:
	virtual void wykonaj()=0;
	virtual int typ()=0;
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
		ProgramLogo::x+=x*cos(ProgramLogo::turn);
		ProgramLogo::y+=y*sin(ProgramLogo::turn);
	}
	Type typ(){return MOVE;}
}

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
		ProgramLogo::turn+=turn;
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
		ProgramLogo::down=down;
	}
	Type typ(){return PUTPEN;}
};

class ProgramLogo
{
	int x,y,turn;
	bool down;
	list<Command*> polecenia;
public:
	ProgramLogo(int x=0, int y=0, int turn=0, bool down=true)
	{
		this->x=x; this->y=y;this->turn=turn; this->down=down;
	}
	ProgramLogo& operator = (ProgramLogo &p)
	{
		x=p.x; y=p.y; turn=p.turn; down=p.down;
		list<Command*>::iterator it;
		Command *nowy;
		for(it=p.polecenia.begin();it!= p.polecenia.end();it++)
		{

			switch(it->typ())
			{
				case MOVE:nowy = new Move(it->x,it->y); break;
				case TURN:nowy = new Turn(it->turn); break;
				case PUTPEN:nowy = new PutPen(it->down); break;
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
		for(it=p.polecenia.begin();it!= p.polecenia.end();it++)
		{
			delete *it;
		}
	}
	void newCommand(Command *c)
	{
		polecenia.push_back(c);
	}
};