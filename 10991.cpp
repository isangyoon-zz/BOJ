#include <cstdio>

int N;

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  if (N == 1) putchar('*');
  else
  {
    for (int i = 1; i <= N; ++i)
    {
      for (int j = 1; j <=  N - i; ++j) putchar(' ');
      for (int j = 1; j <= i; ++j) printf("* ");

      putchar('\n');
    }
  }

  return 0;
}
