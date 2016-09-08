#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int N, M;
int r, c;
std::vector<std::vector<int>> rows;
std::vector<std::vector<int>> cols;
std::vector<std::string> board;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;
std::vector<int> matched;

auto in_range(int const x, int const y)
{
  return x >= 0 && x < N && y >= 0 && y < M;
}

void row_fill(int const x, int const y)
{
  rows[x][y] = r;

  const int next_x = x;
  const int next_y = y + 1;
  if (in_range(next_x, next_y) && board[next_x][next_y] == '*' && !rows[next_x][next_y])
  {
    row_fill(next_x, next_y);
  }
}

void col_fill(int const x, int const y)
{
  cols[x][y] = c;

  const int next_x = x + 1;
  const int next_y = y;
  if (in_range(next_x, next_y) && board[next_x][next_y] == '*' && !cols[next_x][next_y])
  {
    col_fill(next_x, next_y);
  }
}

auto dfs(int const v)
{
  if (visited[v]) return false;
  visited[v] = true;

  for (auto const& u : adj[v])
  {
    if (matched[u] == -1 || dfs(matched[u]))
    {
      matched[u] = v;

      return true;
    }
  }

  return false;
}

auto flow(int const n)
{
  std::fill(std::begin(matched), std::end(matched), -1);

  int match = 0;
  for (auto i = 0; i < n; ++i)
  {
    std::fill(std::begin(visited), std::end(visited), false);

    if (dfs(i)) ++match;
  }

  return match;
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N >> M;

  board.resize(N);
  rows.resize(N, std::vector<int>(M, 0));
  cols.resize(N, std::vector<int>(M, 0));

  for (auto i = 0; i < N; ++i) std::cin >> board[i];

  for (auto i = 0; i < N; ++i)
  {
    for (auto j = 0; j < M; ++j)
    {
      if (board[i][j] == '*' && !rows[i][j])
      {
        ++r;
        row_fill(i, j);
      }
    }
  }

  for (auto i = 0; i < N; ++i)
  {
    for (auto j = 0; j < M; ++j)
    {
      if (board[i][j] == '*' && !cols[i][j])
      {
        ++c;
        col_fill(i, j);
      }
    }
  }

  int size = std::max(r, c);
  adj.resize(size);
  visited.resize(size, false);
  matched.resize(size, -1);

  for (auto i = 0; i < N; ++i)
  {
    for (auto j = 0; j < M; ++j)
    {
      if (rows[i][j] > 0 && cols[i][j] > 0)
      {
        adj[rows[i][j] - 1].push_back(cols[i][j] - 1);
      }
    }
  }

  std::cout << flow(size) << std::endl;

  return 0;
}
