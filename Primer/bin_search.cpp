#include <iostream>
#include <vector>

int bin_search(std::vector<int>& v, int num);

int main(void)
{
	using std::cout;
	using std::endl;
	using std::vector;

	std::vector<int> v = {1,3,12,13,14,15,17,19,25};
	cout << bin_search(v, 1) << endl;
}

int bin_search(std::vector<int>& v, int num)
{
	auto beg = v.begin(), end = v.end(), mid = v.begin() + v.size()/2;
	while (beg < end)
	{
		if (*mid == num)
		{
			return mid - v.begin();
		}
		else if (*mid > num)
		{
			end = mid;
		}
		else // *mid < num
		{
			beg = mid + 1;
			
		}
		mid = beg + (end - beg)/2;
	}
	return -1;
}	
