//Find best possible buy/sell pair for greatest profit

#include <iostream>
#include <vector>

double buy_sell_stock(const std::vector<double>& prices)
{
	double max_profit = 0;
	double min_seen = std::numeric_limits<double>::max();

	for (const auto& price : prices)
	{

		max_profit = std::max(price - min_seen, max_profit);
		


		min_seen = std::min(price,min_seen);

	}
	return max_profit;
}


int main()
{
	std::vector<double> v = {310,310,275,275,260,260,260,230,290,230};
	std::cout << buy_sell_stock(v) << std::endl;
	return 0;
}
