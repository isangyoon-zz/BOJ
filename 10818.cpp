#include <cstdio>

int N;

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  int min = 1000001;
  int max = 0;

  while (N--)
  {
    int number;
    scanf("%d", &number);

    min = (min > number) ? number : min;
    max = (number > max) ? number : max;
  }

  printf("%d %d\n", min, max);

  return 0;
}
