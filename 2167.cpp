#include <iostream>

int N, M;
int K;

long long dp[10001][301];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);

	std::cin >> N >> M;

	for (auto i = 1; i <= N; ++i)
	{
		for (auto j = 1; j <= M; ++j)
		{
			long long num;
			std::cin >> num;

			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + num;
		}
	}

	std::cin >> K;

	for (auto i = 1; i <= K; ++i)
	{
		int  x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;

		std::cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << std::endl;;
	}

	return 0;
}
