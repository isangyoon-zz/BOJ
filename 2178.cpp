#include <iostream>
#include <cstdio>
#include <queue>

const int next[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int N, M;
int maze[101][101];
int visited[101][101];

bool inRange(std::pair<int, int> const position)
{
  return (position.first > 0) && (position.first <= N) && (position.second > 0) && (position.second <= M);
}

void bfs(std::pair<int, int> const position)
{
  std::queue<std::pair<int, int> > q;

  q.push(position);
  visited[position.first][position.second] = 1;

  while (!q.empty())
  {
    const std::pair<int, int> current = q.front();
    q.pop();

    for (auto i = 0; i < 4; ++i)
    {
      const int next_x = current.first + next[i][0];
      const int next_y = current.second + next[i][1];

      if (inRange({next_x, next_y}) && maze[next_x][next_y] && visited[next_x][next_y] == 0)
      {
        visited[next_x][next_y] += visited[current.first][current.second] + 1;
        q.push( {next_x, next_y} );
      }
    }
  }
}

int main(int argc, char const** argv)
{
  scanf("%d %d", &N, &M);


  std::cin.ignore();

  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= M; ++j)
    {
      scanf("%1d", &maze[i][j]);
    }
  }

  bfs({1, 1});
  std::cout << visited[N][M] << std::endl;

  return 0;
}
