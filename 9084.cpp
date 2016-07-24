#include <iostream>
#include <algorithm>

int T;
int N;
int M;
int C[21];
long long dp[10001];

int main(int argc, char** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> T;
  for (auto TC = 1; TC <= T; ++TC)
  {
    std::fill(std::begin(C), std::end(C), 0);
    std::fill(std::begin(dp), std::end(dp), 0);

    std::cin >> N;
    for (auto i = 1; i <= N; ++i)
    {
      std::cin >> C[i];
    }

    std::cin >> M;

    dp[0] = 1;
    for (auto i = 1; i <= N; ++i)
    {
      for (auto j = C[i]; j <= M; ++j)
      {
        dp[j] += dp[j - C[i]];
      }
    }

    std::cout << dp[M] << std::endl;
  }

  return 0;
}
