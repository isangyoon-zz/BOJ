#include <cstdio>
#include <algorithm>

int N;
int num[1000001];

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  std::for_each(std::begin(num), std::begin(num) + N, [](int& n) { scanf("%d", &n); });

  std::sort(std::begin(num), std::begin(num) + N);
  std::for_each(std::begin(num), std::begin(num) + N, [](int const& n) { printf("%d\n", n); });

  return 0;
}
