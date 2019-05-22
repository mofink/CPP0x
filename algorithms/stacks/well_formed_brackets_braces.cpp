#include <iostream>
#include <string>
#include <stack>


bool check_brackets(std::string& str)
{
	std::stack<char> stk;
	for (int i = 0; i < str.size(); ++i)
	{
		char token = str[i];
		if (token == '}' || token == ']' || token == ')')
		{
			if (!stk.empty())
			{
				switch(token)	
				{
					case ')':
						if (stk.top() != '(')
							return false;
					break;
					
					case ']':
						if (stk.top() != '[')
							return false;
					break;
					
					case '}':
						if (stk.top() != '{')
							return false;
					break;
				} 	
				stk.pop();
			}
			else
			{
				return false;
			}
		}

		else //is { [ or (
		{
			stk.emplace(token);
		}
	}

	if (!stk.empty())
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	std::string arg = "()";
	std::cout << check_brackets(arg) << std::endl;
	return 0;
}

