class Zwierze
{
};

class Kura: public Zwierze
{

};

class Pies: public Zwierze
{

};

class Mucha: public Zwierze
{

};

void copy(Zwierze *source[], int n; Zwierze *destination[])
{
	for(int i=0;i<n;i++)
	{
		if(typeid(*source[i])==typeid(Kura)
			destination[i]=new Kura(*(Kura*)source[i]);
		if(typeid(*source[i])==typeid(Pies)
			destination[i]=new Pies(*(Pies*)source[i]);
		if(typeid(*source[i])==typeid(Mucha)
			destination[i]=new Mucha(*(Mucha*)source[i]);
	}
}