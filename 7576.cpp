#include <iostream>
#include <queue>

const int next[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int N, M;
int box[1001][1001];
int visited[1001][1001];
std::queue<std::pair<int, int> > q;

bool inRange(std::pair<int, int> const position)
{
  return (position.first >= 1) && (position.first <= N) && (position.second >= 1) && (position.second <= M);
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> M >> N;

  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= M; ++j)
    {
      std::cin >> box[i][j];
      visited[i][j] = -1;

      if (box[i][j] == 1)
      {
        q.push({i, j});
        visited[i][j] = 0;
      }
    }
  }

  while (!q.empty())
  {
    const std::pair<int, int> current = q.front();
    q.pop();

    for (auto i = 0; i < 4; ++i)
    {
      const int next_x = current.first + next[i][0];
      const int next_y = current.second + next[i][1];

      if (inRange({next_x, next_y}) && !box[next_x][next_y] && visited[next_x][next_y] == -1)
      {
        visited[next_x][next_y] = visited[current.first][current.second] + 1;
        q.push( {next_x, next_y} );
      }
    }
  }

  int answer = 0;
  bool flag = true;
  for (auto i = 1; i <= N && flag; ++i)
  {
    for (auto j = 1; j <= M && flag; ++j)
    {
      answer = std::max(answer, visited[i][j]);

      if ((box[i][j] == 0) && (visited[i][j] == -1)) answer = -1, flag = false;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
