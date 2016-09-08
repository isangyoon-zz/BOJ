#include <cstdio>
#include <unordered_set>

int N, M;
std::unordered_set<int> A;

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  for (auto i = 1; i <= N; ++i)
  {
    int number;
    scanf("%d", &number);

    A.insert(number);
  }

  scanf("%d", &M);
  while (M--)
  {
    int number;
    scanf("%d", &number);

    printf("%d\n", A.find(number) != std::end(A));
  }

  return 0;
}
