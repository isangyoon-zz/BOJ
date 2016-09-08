#include <cstdio>

int N;

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  if (N == 1) putchar('*');
  else if (N == 2) printf(" *\n***\n");
  else
  {
    for (int i = 1; i < N; ++i) putchar(' ');
    printf("*\n");

    for (int i = 1; i <= N - 2; ++i)
    {
      for (int j = 1; j < N - i; ++j) putchar(' ');
      putchar('*');
      for (int j = 1; j <= 2 * i - 1; ++j) putchar(' ');
      printf("*\n");
    }

    for (int i = 1; i <= 2 * N - 1; ++i) putchar('*');

    putchar('\n');
  }

  return 0;
}
