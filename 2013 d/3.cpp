class TextArrayIterator
{
	TextArray *arr;
	int poz;
	public:
	TextArrayIterator(TextArray *array){arr=array;poz=0;}
	bool good()
	{
		if(poz<arr->zajete)
		{
			return true;
		}
		return false;
	}
	void next(){poz++;};
	const char * get()
	{
		if(good())
		{
			return arr->array[poz];
		}
		return '\0';
	}
};

int main()
{
	TextArray arr;
	TextArrayIterator it(&arr);
	while(it.good())
	{
		cout<<it.get();
		it.next();
	}

}
