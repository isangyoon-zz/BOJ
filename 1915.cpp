#include <cstdio>
#include <iostream>
#include <algorithm>

int N, M;
int dp[1001][1001];

int main(int argc, char** argv)
{
  std::cin >> N >> M;

  int answer = 0;
  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= M; ++j)
    {
      int square;
      scanf("%1d", &square);

      if (square)
      {
        dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
        answer = std::max(answer, dp[i][j]);
      }
    }
  }

  std::cout << answer * answer << std::endl;

  return 0;
}
