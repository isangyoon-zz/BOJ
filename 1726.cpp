#include <iostream>
#include <tuple>
#include <queue>

const int next[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int direction[5] = {0, 2, 1, 4, 3};

int N, M;
int map[101][101];
bool visited[101][101][5];

std::tuple<int, int, int> start;
std::tuple<int, int, int> end;

int answer = 0;

void bfs()
{
  const auto start_x = std::get<0>(start);
  const auto start_y = std::get<1>(start);
  const auto start_dir = std::get<2>(start);

  const auto end_x = std::get<0>(end);
  const auto end_y = std::get<1>(end);
  const auto end_dir = std::get<2>(end);

  std::queue<std::tuple<int, int, int, int> > q;
  q.push(std::make_tuple(start_x, start_y, start_dir, 0));
  visited[start_x][start_y][start_dir] = true;

  while (!q.empty())
  {
    const auto current = q.front();
    q.pop();

    const auto x = std::get<0>(current);
    const auto y = std::get<1>(current);
    const auto dir = std::get<2>(current);
    auto count = std::get<3>(current);

    if ((x == end_x) && (y == end_y) && (dir == end_dir))
    {
      answer = count;

      break;
    }

    // Go K
    for (auto k = 1; k <= 3; ++k)
    {
      const auto next_x = x + (next[dir][0] * k);
      const auto next_y = y + (next[dir][1] * k);

      if (next_x < 1 || next_x > N || next_y < 1 || next_y > M || map[next_x][next_y] == 1) break;
      if (visited[next_x][next_y][dir]) continue;

      visited[next_x][next_y][dir] = true;
      q.push(std::make_tuple(next_x, next_y, dir, count + 1));
    }

    // Turn dir
    for (auto i = 1; i <= 4; ++i)
    {
      if ((i == dir) || (i == direction[dir])) continue;
      if (visited[x][y][i]) continue;

      visited[x][y][i] = true;
      q.push(std::make_tuple(x, y, i, count + 1));
    }
  }
}

int main(int argc, char const** argv)
{
  std::cin >> N >> M;

  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= M; ++j)
    {
      std::cin >> map[i][j];
    }
  }

  int x, y, d;

  std::cin >> x >> y >> d;
  start = std::make_tuple(x, y, d);

  std::cin >> x >> y >> d;
  end = std::make_tuple(x, y, d);

  bfs();

  std::cout << answer << std::endl;

  return 0;
}
