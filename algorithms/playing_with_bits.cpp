#include <iostream>
#include <vector>

#define PRINT(x) std::cout<<x<<std::endl; //debugging

//neat post about XOR https://stackoverflow.com/a/16285195/6521643

int count_1_bits(unsigned char* data)
{
	int counter = 0;
	while (*data)
	{
		counter += *data & 1; 
		*data >>= 1; //slide *data across the window at the least significant bit
	}
	return counter;
}

bool get_parity(unsigned char* data) //odd parity returns 1
{
	
	int ans = 0;
	while (*data)
	{
		/*
		xor toggles a bit (bool value) on and off
		similar to the sliding window in the previous function
		ans ^= (*data & 1); 
		*data >>= 1;
		
		we can eke out even more efficiency if we just drop the lower bits instead of shifting
		*/
		ans ^= 1;
		*data &= (*data - 1); 

	}
	return ans;
	
	//finally, we can capitalize on the properties of xor,
	//namely that the parity of 11011110 == parity of 1101^1110 == parity of 11^01^11^10
	/*
	int i = 32;
	while (i)
	{
		*data ^= *data >> i;
		i /= 2;
	}
	return *data & 1;
	*/

}


int main()
{
	unsigned char a = 6;
	unsigned char* data = &a;
	
	std::cout << get_parity(data) << std::endl;
	return 0;
}
