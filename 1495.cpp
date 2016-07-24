#include <iostream>
#include <algorithm>

const int INF = -(1 << 30);

int V[101];
int dp[101][1001];
int N, S, M;

int solve(int index, int volume)
{
 if (volume < 0 || volume > M) return INF;
 if (index == N) return volume;

 int& cache = dp[index][volume];
 if (cache != -1) return cache;
 cache = std::max(solve(index + 1, volume - V[index + 1]), solve(index + 1, volume + V[index + 1]));

 return cache;
}

int main(int argc, char** argv)
{
  std::cin >> N >> S >> M;

  std::fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), -1);

  for (auto i = 1; i <= N; ++i)
  {
    std::cin >> V[i];
  }

  auto answer = solve(0, S);

  if (answer == INF) std::cout << "-1" << std::endl;
  else std::cout << answer << std::endl;

  return 0;
}
