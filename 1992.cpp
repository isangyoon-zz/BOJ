#include <cstdio>

const int MAX = 1e2;

int N;
int data[MAX][MAX];

bool check(int const x, int const y, std::size_t n)
{
  for (auto i = x; i < x + n; ++i)
  {
    for (auto j = y; j < y + n; ++j)
    {
      if (data[i][j] != data[x][y]) return false;
    }
  }

  return true;
}

void compress(int const x, int const y, std::size_t n)
{
  if (check(x, y, n)) printf("%d", data[x][y]);
  else
  {
    printf("(");

    int m = static_cast<int>(n / 2);
    for (auto i = 0; i < 2; ++i)
    {
      for (auto j = 0; j < 2; ++j)
      {
        compress(x + i * m, y + j * m, m);
      }
    }

    printf(")");
  }
}

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  for (auto i = 0; i < N; ++i)
  {
    for (auto j = 0; j < N; ++j)
    {
      scanf("%1d", &data[i][j]);
    }
  }

  compress(0, 0, N);
  std::putchar('\n');

  return 0;
}
