#include <iostream>
#include <string>

std::istream& read_to_eof(std::istream& s)
{
	int var;
	while (s >> var)
	{
		std::cout << var;
	}
	s.clear();
	return s;

}

int main()
{
	read_to_eof(std::cin);
	return 0;
}

