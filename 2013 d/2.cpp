class TextArray
{
	char **array;
	int ilosc;
	int zajete;
	public:
	TextArray(){ilosc=10; array=new char*[10];zajete=0;}
	~TextArray()
	{
		for(int i=0;i<zajete;i++)
			delete array[i];
		delete [] array;
	}
	void pushBack(const char *txt)
	{
		if(zajete+1>ilosc)
		{
			char** newarray=new char*[ilosc+10];
			for(int i=0;i<zajetel;i++)
			{
				newarray[i]=new char[strlen(array[i]+1];
				strcpy(newarray[i],array[i]);
			}
			ilosc+=10;
		}
		array[zajete]=new char[strlen(txt)+1];
		strcpy(array[zajete],txt);
		zajete++;
	}
	void docopy(const TextArray &ta)
	{
		array=new char*[ilosc];
		for (int i=0; i<zajete; i++)
		{
			array[i]=new char [strlen(ta.array[i])+1];
			strcpy(array[i],ta.array[i]);
		}
	}
	TextArray(const TextArray &ta)
	{
		docopy(ta);
	}
	TextArray & operator = (const TextArray &ta)
	{
		if (ta!=*this)
		{
			this->~TextArray;
			docopy(ta);
		}
		return *this;
	}
};
int main()
{
	ifstream file("input.txt");
	string str;
	TextArray arr;
	while(!file.eof())
	{
		getline(file, str);
		arr.pushBack(str.c_str());
	}
}
