#include <cstdio>

int N;

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  for (int i = 1; i <= 9; printf("%d * %d = %d\n", N, i, N * i), ++i);

  return 0;
}
