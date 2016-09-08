#include <iostream>

int T;
int N;
int dp[11] = { 1, };

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  for (auto i = 1; i < 11; ++i)
  {
    if (i >= 1) dp[i] += dp[i - 1];
    if (i >= 2) dp[i] += dp[i - 2];
    if (i >= 3) dp[i] += dp[i - 3];
  }

  std::cin >> T;
  while (T--)
  {
    std::cin >> N;

    std::cout << dp[N] << std::endl;
  }

  return 0;
}
