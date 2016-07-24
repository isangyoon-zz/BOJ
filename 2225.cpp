#include <iostream>
using namespace std;

int N, K;
int dp[201][201];

int main(int argc, char** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N >> K;

  for (auto i = 0; i <= N; ++i)
  {
    dp[1][i] = 1;
    dp[2][i] = i + 1;
  }

  for (auto k = 3; k <= K; ++k)
  {
    for (auto i = 0; i <= N; ++i)
    {
      for (auto j = 0; j <= i; ++j)
      {
        dp[k][i] = (dp[k][i] + dp[k - 1][i - j]) % 1000000000;
      }
    }
  }

  std::cout << dp[K][N] << std::endl;

  return 0;
}
