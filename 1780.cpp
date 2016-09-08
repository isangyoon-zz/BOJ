#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> paper;
int answers[3];

bool check(std::size_t const n, int const x, int const y)
{
  for (auto i = x; i < x + n; ++i)
  {
    for (auto j = y; j < y + n; ++j)
    {
      if (paper[i][j] != paper[x][y]) return false;
    }
  }

  return true;
}

void cut(std::size_t const n, int const x, int const y)
{
  if (check(n, x, y))
  {
    ++answers[paper[x][y] + 1];

    return;
  }

  std::size_t m = n / 3;
  for (auto i = 0; i < 3; ++i)
  {
    for (auto j = 0; j < 3; ++j)
    {
      cut(m, x + i * static_cast<int>(m), y + j * static_cast<int>(m));
    }
  }
}


int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;
  paper.assign(N, std::vector<int>(N, 0));

  for (auto i = 0; i < N; ++i)
  {
    for (auto j = 0; j < N; ++j)
    {
      std::cin >> paper[i][j];
    }
  }

  cut(N, 0, 0);

  for (auto const answer : answers)
  {
    std::cout << answer << std::endl;
  }

  return 0;
}
