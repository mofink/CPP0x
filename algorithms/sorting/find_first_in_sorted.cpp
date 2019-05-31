//find first occurence of k in a sorted vector in log time

//binary search is generally log time but fails when k is repeated in the input
//naive approach is using binary search and moving backwards is still linear time -- consider case where are elements equal k

#include <iostream>
#include <vector>
#include <algorithm>


int find_first_in_sorted(const std::vector<int>& vec, int k)
{
	int lower = 0, upper = vec.size() - 1, ans = -1;

	while (lower <= upper)
	{
		int mid = lower + (upper - lower)/2;
		if (vec[mid] == k)
		{
			ans = mid;
			upper = mid - 1; //we can safely discard any index greater than mid since we are only looking for the first k
		}

		else if (vec[mid] > k)
		{
			upper = mid - 1;
		}
		else //vec[mid] < k
		{
			lower = mid + 1;
		}
	}
	return ans;
}

int main()
{
	std::vector<int> vec = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
	std::cout << find_first_in_sorted(vec,108) << std::endl;
	return 0;
}
