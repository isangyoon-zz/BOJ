#include <cstdio>

int N;

void hanoi(int const x, int const y, int const n)
{
  if (n == 0) return;

  hanoi(x, 6 - x - y, n - 1);
  printf("%d %d\n", x, y);
  hanoi(6 - x - y, y, n - 1);
}

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  printf("%d\n", (1 << N) - 1);
  hanoi(1, 3, N);

  return 0;
}
