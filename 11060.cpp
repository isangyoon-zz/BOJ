#include <iostream>

int N;
int dp[1001];

int main(int const argc, char const** argv)
{
  std::cin >> N;

  dp[1] = 1;
  for (auto i = 1; i <= N; ++i)
  {
    int jump;
    std::cin >> jump;

    if (dp[i])
    {
      for (auto j = i + 1; j <= i + jump && j <= N; ++j)
      {
        if (!dp[j] || dp[j] > dp[i] + 1)
        {
          dp[j] = dp[i] + 1;
        }
      }
    }
  }

  std::cout << dp[N] - 1 << std::endl;

  return 0;
}
