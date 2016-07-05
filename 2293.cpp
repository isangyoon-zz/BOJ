#include <iostream>

int N, K;

long long dp[10001];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);

	std::cin >> N >> K;

	dp[0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		int coin;
		std::cin >> coin;

		for (int j = coin; j <= K; ++j)
		{
			dp[j] += dp[j - coin];
		}
	}

	std::cout << dp[K] << std::endl;

	return 0;
}
