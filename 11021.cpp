#include <cstdio>

int T;
int A, B;

int main(int const argc, char const** argv)
{
  scanf("%d", &T);

  for (int TC = 1; TC <= T; ++TC)
  {
    scanf("%d %d", &A, &B);

    printf("Case #%d: %d\n", TC, (A + B));
  }

  return 0;
}
