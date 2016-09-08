#include <iostream>
#include <cstdio>
#include <numeric>

int N;
int numbers[101];

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  for (auto i = 0; i < N; ++i)
  {
    scanf("%1d", &numbers[i]);
  }

  printf("%d\n", std::accumulate(std::begin(numbers), std::end(numbers), 0));

  return 0;
}
