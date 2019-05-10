//increments base 10 number encoded in a vector, including carry digits

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

std::vector<int>& addOne(std::vector<int>* vec_ptr)
{
	std::vector<int>& vec = *vec_ptr;
	auto iter = vec.end() - 1;
	while (++*iter % 10 == 0)
	{
		*iter = 0;
		--iter;
	}

	bool flag = true;
	for (int i : vec)
	{

		if (i != 0)
		{
			flag = false;
			break;
		}
	}
	if (flag == true)
	{
		vec.insert(vec.begin(),1);
	}
	return vec;
}


int main()
{
	std::vector<int> v = {9,9,9};
	print(addOne(&v));
	return 0;
}
