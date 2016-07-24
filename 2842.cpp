#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

const int INFINITE = 1 << 30;
const int next[8][2] = {{0, 1}, {0,-1}, {1, 0}, {-1,0}, {1, 1}, {1,-1}, {-1,1}, {-1,-1}};

int N;
char map[51][51];
int altitude[51][51];

bool inRange(int const x, int const y)
{
  return ((x > 0) && (x <= N) && (y > 0) && (y <= N));
}

int dijkstra(int const x, int const y, int const alt)
{
  std::vector<std::vector<bool> > visited(N + 1, std::vector<bool>(N + 1, false));

  auto compare = [](std::tuple<int, int, int> const& lhs, std::tuple<int, int, int> const& rhs) { return std::get<2>(lhs) > std::get<2>(rhs); };

  std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int> >, decltype(compare)> pq(compare);
  pq.push(std::make_tuple(x, y, altitude[x][y]));

  int max = 0;
  while (!pq.empty())
  {
    auto const current = pq.top();
    pq.pop();

    const int cx = std::get<0>(current);
    const int cy = std::get<1>(current);
    const int ca = std::get<2>(current);

    if (map[cx][cy] == 'K') max = std::max(max, ca);

    if (visited[cx][cy]) continue;
    visited[cx][cy] = true;

    for (auto i = 0; i < 8; ++i)
    {
      const int next_x = cx + next[i][0];
      const int next_y = cy + next[i][1];

      if (inRange(next_x, next_y))
      {
        const int next_alt = std::max(ca, altitude[next_x][next_y]);

        if (!visited[next_x][next_y] && altitude[next_x][next_y] >= alt)
        {
          pq.push(std::make_tuple(next_x, next_y, next_alt));
        }
      }
    }
  }

  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= N; ++j)
    {
      if (map[i][j] == 'K' && !visited[i][j]) return INFINITE;
    }
  }

  return max;
}

int main(int argc, char const** argv)
{
  std::cin >> N;

  int x = 0, y = 0;
  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= N; ++j)
    {
      std::cin >> map[i][j];

      if (map[i][j] == 'P')
      {
        x = i;
        y = j;
      }
    }
  }

  std::vector<int> altitudes;
  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= N; ++j)
    {
      std::cin >> altitude[i][j];
      altitudes.push_back(altitude[i][j]);
    }
  }

  std::sort(std::begin(altitudes), std::end(altitudes));
  altitudes.erase(std::unique(std::begin(altitudes), std::end(altitudes)), std::end(altitudes));

  int start_altitude = altitude[x][y];
  int answer = INFINITE;

  for (auto it = std::begin(altitudes); it != std::end(altitudes) && start_altitude >= (*it); ++it)
  {
    answer = std::min(answer, dijkstra(x, y, (*it)) - (*it));
  }

  std::cout << answer << std::endl;

  return 0;
}
