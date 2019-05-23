//find non-repeated element in array in linear time

#include <iostream>
#include <vector>


int no_double(std::vector<int>& vec)
{
	//the trick is to recall that (n^1 = ~n) n^n = 0 and n^0 = n
	//intuitively we can use the fact that XOR is associative

	int num = 0;
	for (int i: vec)
	{
		num = num^i;
	}
	return num;
}

int main()
{
	std::vector<int> vec = {1, 2, 5, 4, 6, 8, 9, 2, 1, 4, 5, 8, 9};
	std::cout << no_double(vec) << std::endl;
	return 0;
}

