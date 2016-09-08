#include <iostream>
#include <algorithm>

int N;
int a[1001];
int dp[1001];

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  for (auto i = 1; i <= N; ++i)
  {
    std::cin >> a[i];
  }

  for (auto i = N; i; --i)
  {
    dp[i] = 1;

    for (auto j = N; j > i; --j)
    {
      if (a[i] > a[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
    }
  }

  int answer = 0;
  for (auto i = 1; i <= N; ++i)
  {
    answer = std::max(answer, dp[i]);
  }

  std::cout << answer << std::endl;

  return 0;
}
