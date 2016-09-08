#include <cstdio>

int N;

int main(int const argc, char const** argv)
{
  scanf("%d", &N);
  printf("%d\n", (N * (N + 1)) / 2);

  return 0;
}
