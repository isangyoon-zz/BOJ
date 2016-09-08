#include <cstdio>

int N, M;
int A[50][50];
int B[50][50];

void flip(int const x, int const y)
{
  for (auto i = x - 1; i <= x + 1; ++i)
  {
    for (auto j = y - 1; j <= y + 1; ++j)
    {
      A[i][j] = 1 - A[i][j];
    }
  }
}

int main(int const argc, char const** argv)
{
  scanf("%d %d", &N, &M);

  for (auto i = 0; i < N; ++i)
  {
    for (auto j = 0; j < M; ++j)
    {
      scanf("%1d", &A[i][j]);
    }
  }

  for (auto i = 0; i < N; ++i)
  {
    for (auto j = 0; j < M; ++j)
    {
      scanf("%1d", &B[i][j]);
    }
  }

  int answer = 0;
  for (auto i = 0; i < N - 2; ++i)
  {
    for (auto j = 0; j < M - 2; ++j)
    {
      if (A[i][j] != B[i][j])
      {
        flip(i + 1, j + 1);
        ++answer;
      }
    }
  }

  bool c = true;
  for (auto i = 0; i < N; ++i)
  {
    for (auto j = 0; j < M; ++j)
    {
      if (A[i][j] != B[i][j])
      {
        c = false;

        break;
      }
    }
  }

  printf("%d\n", c ? answer : -1);

  return 0;
}
