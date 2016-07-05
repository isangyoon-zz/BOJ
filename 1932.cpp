#include <iostream>

int N;
unsigned long long dp[501][501];

unsigned long long max(int const& lhs, int const& rhs)
{
	return lhs > rhs ? lhs : rhs;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);

	std::cin >> N;

	unsigned long long num;
	std::cin >> num;

	dp[1][1] = num;

	unsigned long long answer = 0;
	for (auto i = 2; i <= N; ++i)
	{
		for (auto j = 1; j <= i; ++j)
		{
			std::cin >> num;

			dp[i][j] = (j == 1) ? dp[i - 1][j] + num : max(dp[i][j], max(dp[i - 1][j - 1] + num, dp[i - 1][j] + num));
			answer = max(answer, dp[i][j]);
		}
	}

	std::cout << answer << std::endl;

	return 0;
}
