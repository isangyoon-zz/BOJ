#include <cstdio>

int N;

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  for (int i = 1; i <= N; ++i)
  {
    for (int j = 1; j <= N - i + 1; ++j) putchar('*');

    putchar('\n');
  }

  return 0;
}
