#include <iostream>
#include <algorithm>

int N;
int W[11][11];
int dp[11][1 << 11];

int tsp(int v, int visited)
{
  if (visited == ((1 << N) - 1))
  {
    if (W[v][1]) return W[v][1];
  }

  int& cache = dp[v][visited];
  if (cache) return cache;

  cache = 1 << 30;
  for (auto i = 1; i <= N; ++i)
  {
    if (!(visited & (1 << (i - 1))) && W[v][i])
    {
      cache = std::min(cache, W[v][i] + tsp(i, visited | (1 << (i - 1))));
    }
  }

  return cache;
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= N; ++j)
    {
      std::cin >> W[i][j];
    }
  }

  std::cout << tsp(1, 1) << std::endl;

  return 0;
}
