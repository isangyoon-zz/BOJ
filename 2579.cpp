#include <iostream>

int N;
int stair[301];
int dp[301];

int max(int const& lhs, int const& rhs)
{
  return lhs > rhs ? lhs : rhs;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);

  std::cin >> N;

  for(int i = 1; i <= N; ++i)
  {
    std::cin >> stair[i];
  }

  dp[1] = dp[0] + stair[1];
  dp[2] = dp[1] + stair[2];
  dp[3] = max(dp[1] + stair[3], dp[0] + stair[2] + stair[3]);

  for(int i = 4; i <= N; ++i)
  {
    dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
  }

  std::cout << dp[N] << std::endl;

  return 0;
}
