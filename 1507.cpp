#include <iostream>
#include <algorithm>

int N;
int roads[21][21];

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;

  int cost = 0;
  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= N; ++j)
    {
      std::cin >> roads[i][j];
      cost += roads[i][j];
    }
  }

  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= N; ++j)
    {
      int min = 2147483647;
      for (auto k = 1; k <= N; ++k)
      {
        if (i != k && j != k)
        {
          min = std::min(min, roads[i][k] + roads[j][k]);
        }
      }

      if (min < roads[i][j])
      {
        std::cout << -1 << std::endl;

        return 0;
      }
      else if (min == roads[i][j])
      {
        cost -= roads[i][j];
      }
    }
  }

  cost >>= 1;
  std::cout << cost << std::endl;

  return 0;
}
