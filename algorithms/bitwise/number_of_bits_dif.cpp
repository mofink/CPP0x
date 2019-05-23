//determine number of bits needed to be flipped to covert one number to another

#include <iostream>

int number_of_bits_to_convert(int a, int b)
{
	int num = a^b; //gives 1s in positions that are different
	//now we count number of 1s
	int counter = 0;
	while (num)	
	{
		counter += 1 & num;
		num >>= 1;
	}
	return counter;
}

int main()
{

	std::cout << number_of_bits_to_convert(31,14) << std::endl;
	return 0;
}

