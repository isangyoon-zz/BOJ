#include <iostream>
#include <algorithm>

int line[201];
int dp[201];
int N;

int main(int argc, char** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  for (auto i = 1; i <= N; ++i)
  {
    std::cin >> line[i];
  }

  int size = 1;
  dp[size] = line[size];
  for (auto i = 2; i <= N; ++i)
  {
    if (line[i] > dp[size])
    {
      dp[++size] = line[i];

      continue;
    }

    auto index = std::lower_bound(dp + 1, dp + size + 1, line[i]) - dp;
    dp[index] = line[i];
  }

  auto answer = N - size;
  std::cout << answer << std::endl;

  return 0;
}
