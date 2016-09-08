#include <cstdio>

int N;

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  for (int i = -N + 1; i <= N - 1; ++i)
  {
    int k = (i < 0) ? ~i + 1: i;

    for (int j = 1; j <= k; ++j) putchar(' ');
    for (int j = 1; j <= N - k; ++j) putchar('*');

    putchar('\n');
  }

  return 0;
}
