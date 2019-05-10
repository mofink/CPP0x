//advance through array A, A[i] is the maximum number of steps you are allowed to take from position i
//Determine whether it is possible to traverse the whole array
//e.g. {3,3,1,0,2,0,1} is possible
// {3,2,0,0,2,0,1} is not, since you get stuck at position 3

#include <iostream>
#include <vector>

bool advance(std::vector<int>* vec_ptr)
{
	std::vector<int>& vec = *vec_ptr;
	
	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = 1; i <= vec[i]; ++i)
		{
			if (vec[i + j] != 0)
			{
				continue;
			}
			return false; //no path found
		}
	}
	return true;

}


int main()
{
	std::vector<int> v = {3,2,0,0,2,0,1};
	std::cout << advance(&v) << std::endl;
	return 0;
}
