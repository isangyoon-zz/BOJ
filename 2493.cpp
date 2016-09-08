#include <cstdio>

int N;
int towel[500001];
int temp[500001];

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  int max = 0;
  for (int i = 1; i <= N; ++i)
  {
    scanf("%d", &towel[i]);

    if(towel[i] > max)
    {
      max = towel[i];
      printf("0 ");
    }
    else
    {
      int j = i - 1;
      for (; towel[j] < towel[i]; j = temp[j]);
      temp[i] = j;

      printf("%d ", j);
    }
  }
  printf("\n");

  return 0;
}
