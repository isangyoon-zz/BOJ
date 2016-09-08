#include <iostream>

int N;
int dp[1001] = { 1, 1, };

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  for (auto i = 2; i <= N; ++i)
  {
    dp[i] = (dp[i - 2] + dp[i - 2] + dp[i - 1]) % 10007;
  }

  std::cout << dp[N] << std::endl;

  return 0;
}
