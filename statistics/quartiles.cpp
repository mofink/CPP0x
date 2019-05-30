//calculuate all three quartile values
//using ints, so there may be some rounding errors

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>


int get_med(std::vector<int>& vec)
{
    int med;
    if (vec.size()%2 == 0) //even
    {
        med = (vec[vec.size()/2] + vec[vec.size()/2 - 1])/2;
    }
    else //odd
    {
        med = vec[vec.size()/2];
    }

    return med;

}


int main()
{
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);

    std::vector<int> vec;
    int val;
    while(ss >> val)
    {
        vec.push_back(val);
    }

    std::sort(vec.begin(),vec.end());
    int med = get_med(vec);

    std::vector<int> first;
    std::vector<int> second;
    for (int i = 0; i < vec.size()/2; ++i)
    {
        first.push_back(vec[i]);
        second.push_back(vec[i+vec.size()/2 + (vec.size()%2 ? 1 : 0)]);
    }

    int q1 = get_med(first);
    int q3 = get_med(second);
    std::cout << q1 << std::endl << med << std::endl << q3 << std::endl;



   

    return 0;
}
