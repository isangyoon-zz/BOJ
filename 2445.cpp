#include <cstdio>

int N;

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  for (int i = -N + 1; i <= N - 1; ++i)
  {
    for (int j = 1, k = (i < 0) ? N + i : N - i; j <= k; ++j) putchar('*');
    for (int j = 1, k = (i < 0) ? -i : i; j <= 2 * k; ++j) putchar(' ');
    for (int j = 1, k = (i < 0) ? N + i : N - i; j <= k; ++j) putchar('*');

    putchar('\n');
  }

  return 0;
}
