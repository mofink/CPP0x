//return the smallest value that cannot be expressed as a subset of an array
//key insight is that if a collection of numbers can be summed up to and including a number V, V+1 is unreachable
//if the next number is greater than V+1 than V+1 is the answer

#include <iostream>
#include <vector>



int get_smallest_val(std::vector<int> vec)
{
	sort(vec.begin(),vec.end());
	int M = 0;
	for (auto i : vec)
	{
		if (i > M + 1)
		{
			return M + 1;
		} 
		else
		{
			M += i;
		}
	}
	return M + 1;
}

int main()
{
	std::vector<int> vec = {12,2,1,15,2,4};
	std::cout << get_smallest_val(vec) << std::endl;
	return 0;
}
