#include <cstdio>

int N;

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  for (int i = -N + 1; i <= N - 1; ++i)
  {
    for (int j = (i < 0) ? -i : i; j > 0; --j) putchar(' ');
    for (int j = 1; j <= 2 * ((i <= 0) ? (N + i) : (N - i)) - 1; ++j) putchar('*');

    putchar('\n');
  }

  return 0;
}
