
#include <iostream>
#include <string>
#include <cmath>


int string_to_int(std::string str)
{
	int ans = 0;
	int val = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		val = str[i] - '0';
		ans = (10 * ans) + val;
	}
	return ans;
}


std::string int_to_string(int num)
{
	std::string str;
	while (num)
	{
		str += '0' + (num%10);
		num /= 10;
	}
	return {str.rbegin(), str.rend()};
}

int main()
{
	std::string str = "241";
	//int num = 241;
	std::cout << string_to_int(str) << std::endl;	
	return 0;
}
