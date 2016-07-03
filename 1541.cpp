#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string const& str, char delim)
{
	std::vector<std::string> result;
	std::stringstream ss(str);

	std::string substr;
	while (std::getline(ss, substr, delim))
	{
		result.push_back(substr);
	}

	return result;
}

int sum(std::string expr)
{
	auto numbers = split(expr, '+');

	auto result = 0;
	for (auto const& number : numbers)
	{
		result += std::stoi(number);
	}

	return result;
}

int main(int argc, char** argv)
{
  std::ios::sync_with_stdio(false);
  
	std::string expression;
	std::cin >> expression;

	auto expr = split(expression, '-');

	std::vector<int> numbers;
	for (auto const& e : expr)
	{
		numbers.push_back(sum(e));
	}

	auto answer = std::accumulate(numbers.begin() + 1, numbers.end(), numbers[0], std::minus<int>());

	std::cout << answer << std::endl;

	return 0;
}
