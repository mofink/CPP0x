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

	HasPtr& operator=(HasPtr& rhs) //copy assignment operator overload
	{
		//need to account for case of self copy, also need to free rhs.ps
		std::string * newp = new std::string(*rhs.ps); //copy VALUE stored in rhs.ps
		delete ps; //free memory held by old pointer
		ps = newp; //copy value from old pointer into new pointer
		
		i = rhs.i;
		return *this;
	}

	~HasPtr() //destructor, needed to free dynimcally allocated memory, everything else is handled implicitly
	{
		delete ps;
	}

	void print()
	{
		std::cout << *ps << std::endl;
	}

private:
	std::string* ps;
	int i;

	
};



int main()
{
	HasPtr obj("string");
	HasPtr obj2;
	obj2 = obj;
	obj2 = obj2;
	obj2.print();
	return 0;
}
