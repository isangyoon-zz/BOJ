#include <iostream>

unsigned long long N;
unsigned long long dp[91][2];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
  std::cin >> N;

  dp[1][0] = 1;
  dp[1][1] = 1;

  for(int i = 2; i <= N; ++i)
  {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    dp[i][1] = dp[i - 1][0];
  }

  std::cout << dp[N][1] << std::endl;

  return 0;
}
