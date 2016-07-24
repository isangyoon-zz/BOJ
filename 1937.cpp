#include <iostream>
#include <algorithm>

const int movement[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int forest[501][501];
bool visited[501][501];
int dp[501][501];

int N;

bool inRange(int x, int  y)
{
  return (x > 0) && (x <= N) && (y > 0) && (y <= N);
}

int eat(int x, int y)
{
  if (!dp[x][y])
  {
    dp[x][y] = 1;

    for (auto i = 0; i < 4; ++i)
    {
      int next_x = x + movement[i][0];
      int next_y = y + movement[i][1];

      if (!inRange(next_x, next_y)) continue;
      if (forest[next_x][next_y] >= forest[x][y]) continue;

      dp[x][y] = std::max(dp[x][y], eat(next_x, next_y) + 1);
    }
  }

  return dp[x][y];
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);

  std::cin >> N;

  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= N; ++j)
    {
      std::cin >> forest[i][j];
    }
  }

  int answer = -1;
  for (auto x = 1; x <= N; ++x)
  {
    for (auto y = 1; y <= N; ++y)
    {
      answer = std::max(answer, eat(x, y));
    }
  }

  std::cout << answer << std::endl;

	return 0;
}
