#include <cstdio>

int N;

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  for (int i = 1; i <= N; ++i)
  {
    for (int j = N - 1; j >= i; --j) putchar(' ');
    for (int j = 1; j <= (2 * i - 1); ++j) putchar('*');

    putchar('\n');
  }

  return 0;
}
