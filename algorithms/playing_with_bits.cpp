#include <iostream>
#include <vector>

//neat post about XOR https://stackoverflow.com/a/16285195/6521643

int count_1_bits(unsigned char* data)
{
	int counter = 0;
	while (*data)
	{
		//slide *data across the window at the least significant bit
		counter += *data & 1; 
		*data >>= 1;
	}
	return counter;
}

bool get_parity(unsigned char* data) //odd parity returns 1
{
	int ans = 0;
	while (*data)
	{
		ans ^= (*data & 1); //xor toggles a bit (bool value) on and off
		*data >>= 1;
	}
	return ans;
}


int main()
{
	return 0;
}
