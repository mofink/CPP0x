//seperating evens and odds in constant space

#include <iostream>
#include <vector>

//utility function to print an arbitrary vector
template<typename T>
void print(std::vector<T> v)
{
	for (auto i : v)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void evenOdd(std::vector<int>* vec_ptr)
{
	std::vector<int>& vec = *vec_ptr;

	//print(vec);

	auto even_ptr = vec.begin();
	auto odd_ptr = vec.end() - 1;

	while (even_ptr < odd_ptr)
	{
		if (*even_ptr % 2 == 0)
		{
			++even_ptr;
		}
		else
		{
			//std::cout << *even_ptr << " " << *odd_ptr << std::endl;
			std::swap(*even_ptr,*odd_ptr--);
		}
	}  
}


int main()
{
	std::vector<int> v = {1,5,2,8,7,4,3,9,6};
	print(v);
	evenOdd(&v);
	print(v);
	return 0;
}
