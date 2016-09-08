#include <iostream>
#include <algorithm>
#include <set>

const int next[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int N;
int map[101][101];
int island[101][101];

std::set<std::pair<int, int> > candidates;

bool inRange(int const x, int const y)
{
  return ((x > 0) && (x <= N) && (y > 0) && (y <= N));
}

void dfs(int const tag, int const x, int const y)
{
  island[x][y] = tag;

  for (auto i = 0; i < 4; ++i)
  {
    const int next_x = x + next[i][0];
    const int next_y = y + next[i][1];

    if (inRange(next_x, next_y) && !island[next_x][next_y])
    {
      if (map[next_x][next_y])
      {
        dfs(tag, next_x, next_y);
      }
      else
      {
        candidates.insert( {x, y} );
      }
    }
  }
}

int main(int argc, char const** argv)
{
  std::cin >> N;

  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= N; ++j)
    {
      std::cin >> map[i][j];
    }
  }

  // Numbering
  int tag = 1;
  for (auto x = 1; x <= N; ++x)
  {
    for (auto y = 1; y <= N; ++y)
    {
      if (map[x][y] && !island[x][y])
      {
        dfs(tag, x, y);
        ++tag;
      }
    }
  }

  // Bridging
  int min = N * N + 1;
  for(auto const c1 : candidates)
  {
    const int x1 = c1.first;
    const int y1 = c1.second;

    for(auto const c2 : candidates)
    {
      const int x2 = c2.first;
      const int y2 = c2.second;

      if (island[x1][y1] == island[x2][y2]) continue;

      int distance = std::abs(x2 - x1) + std::abs(y2 - y1) -1;

      min = (min > distance) ? distance : min;
    }
  }

  std::cout << min << std::endl;

  return 0;
}
