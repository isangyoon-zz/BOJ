#include <cstdio>
#include <algorithm>

int N, K;
int A[50000001];

int main(int const argc, char const** argv)
{
  scanf("%d %d", &N, &K);
  std::for_each(std::begin(A), std::begin(A) + N, [](int& a) { scanf("%d", &a); });

  std::nth_element(std::begin(A), std::begin(A) + (K - 1), std::begin(A) + N);
  printf("%d\n", A[K - 1]);

  return 0;
}
