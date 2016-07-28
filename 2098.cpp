#include <iostream>
#include <algorithm>
#include <cstring>

const int INFINITE = 1 << 30;

int N;
int W[17][17];
int dp[17][1 << 16];

int tsp(int start, int status)
{
  if (status == ((1 << N) - 1)) return W[start][1];
  if (dp[start][status] != -1) return dp[start][status];

  int min = INFINITE;
  for (auto next = 1; next <= N; ++next)
  {
    if ((status & (1 << (next - 1))) || (W[start][next] == INFINITE)) continue;

    min = std::min(min, tsp(next, status | (1 << (next - 1))) + W[start][next]);
  }

  dp[start][status] = min;

  return dp[start][status];
}

int main(int const argc, char const** argv)
{
  std::cin >> N;

  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= N; ++j)
    {
      std::cin >> W[i][j];

      if (W[i][j] == 0) W[i][j] = INFINITE;
    }
  }

  auto answer = INFINITE;
  std::memset(dp, -1, sizeof(dp));
  answer = std::min(answer, tsp(1, 1 << 0));

  std::cout << answer << std::endl;

  return 0;
}
