//check if a string is a palindrome


#include <iostream>
#include <string>

bool check_palindrome(const std::string& str)
{
	auto b = str.begin();
	auto e = str.end() - 1;

	while (b < e)
	{
		if (*b != *e)
		{
			return false;
		}
		++b;
		--e;
	}
	return true;
}


int main()
{
	std::string str = "madamimadam";
	std::cout << check_palindrome(str) << std::endl;	
	return 0;
}
