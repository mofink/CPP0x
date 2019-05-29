#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <string>

int main() {
    int val;
    std::string vals;
    std::vector<double> vec;
    std::getline(std::cin,vals);
    std::stringstream ss(vals);
    while (ss >> val)
    {
        vec.push_back(val);
    }

    //mean
    double sum = 0;
    for (auto i: vec)
    {
        sum += i;
    }
    std::cout<< sum/vec.size() << std::endl;

    //median
    double med;
    std::sort(vec.begin(),vec.end());
    if (vec.size() % 2 == 0) //even
    {
        med = (vec[vec.size()/2] + vec[vec.size()/2 - 1])/2;
    } 
    else
    {
        med = vec[vec.size()/2 + 1];
    }
    std::cout << med << std::endl;

    //mode
    std::map<double, int> freq_count;
    for (auto i: vec)
    {
        freq_count[i]++;
    }

    double max = 0;
    int max_freq = 0;
    for (auto i: freq_count)
    {
        if (i.second > max_freq || (i.second == max && i.first < max))
        {
            max_freq = i.second;
            max = i.first;
        }
    }
    std::cout << max << std::endl;
    return 0;
}
