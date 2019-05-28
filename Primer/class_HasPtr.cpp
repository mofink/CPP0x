//example of a class that has a dynamic ptr data member

#include <iostream>
#include <string>


class HasPtr 
{
public: 
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {} //constructor

	HasPtr(const HasPtr& orig) //dynamically allocate new string and copy old string content rather than the pointer itself
	{
		ps = new std::string(*orig.ps);
		i = orig.i;
	}

	HasPtr& operator=(HasPtr& orig) //copy assignment operator overload, same notes as copy constructor
	{
		ps = new std::string(*orig.ps);
		i = orig.i;

		return *this;
	}

	~HasPtr() //destructor, needed to free dynimcally allocated memory, everything else is handled implicitly
	{
		delete ps;
	}

private:
	std::string* ps;
	int i;

	
};



int main()
{

	return 0;
}
