#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

int main() {

    //read in data
    std::string line;
    std::getline(std::cin,line);
    std::stringstream ss_d(line);
    std::vector<double> data;
    double val;
    while (ss_d >> val)
    {
        data.push_back(val);
    }

    //read in weights, 1 to 1 mapping to data vector
    std::getline(std::cin,line);
    std::stringstream ss_w(line);
    std::vector<double> weights;
    double weight;
    while (ss_w >> weight)
    {
        weights.push_back(weight);
    }

    double weighted_avg = 0;
    for (int i = 0; i < data.size(); ++i)
    {
        weighted_avg += (data[i] * weights[i]);
    }

    //get total weight
    double total_weight = 0;
    for (auto i : weights)
    {
        total_weight += i;
    }
    
    //I HATE printing doubles. Also my answer might be slightly off because decimal precision is whack 
    std::cout << std::fixed;
    std::cout.precision(1);
    std::cout << weighted_avg/total_weight;

    return 0;
}
