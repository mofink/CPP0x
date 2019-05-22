#include <iostream>
#include <string>
#include <stack>
#include <sstream>

int reverse_polish_calc(const std::string& str)
{
	std::stack<int> intermediate_result;
	std::stringstream ss(str);
	const char delim = ',';
	std::string token;

	while (getline(ss,token,delim))
	{

		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			const int y = intermediate_result.top();
			intermediate_result.pop();
			const int x = intermediate_result.top();
			intermediate_result.pop();


			switch(token.front())
			{
				case '+':
					intermediate_result.emplace(x + y);
					break;
				case '-':
					intermediate_result.emplace(x - y);
					break;
				case '*':
					intermediate_result.emplace(x * y);
					break;
				case '/':
					intermediate_result.emplace(x / y);
					break;
			}
		}
		else //token is a number
		{
			intermediate_result.emplace(stoi(token));
		}
	} 
	return intermediate_result.top();
}

int main()
{
	std::cout << reverse_polish_calc("3,4,+,2,*,1,+") << std::endl;
	return 0;
}

