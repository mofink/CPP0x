#include <iostream>
#include <vector>

//neat post about XOR https://stackoverflow.com/a/16285195/6521643

int count_1_bits(unsigned char* data)
{
	int counter = 0;
	while (*data)
	{
		counter += *data & 1;
		x >>= 1;
	}
	return counter;
}

bool get_parity(unsigned char* data)
{
	int counter = count_1_bits(data);
	if (counter % 2 == 0) //even
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	std::vector<int> vec = {12,2,1,15,2,4};
	std::cout << get_smallest_val(vec) << std::endl;
	return 0;
}
