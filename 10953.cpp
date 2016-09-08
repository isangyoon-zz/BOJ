#include <cstdio>

int T;
int A, B;

int main(int const argc, char const** argv)
{
  scanf("%d", &T);

  while (T--)
  {
    scanf("%d,%d", &A, &B);

    printf("%d\n", (A + B));
  }

  return 0;
}
