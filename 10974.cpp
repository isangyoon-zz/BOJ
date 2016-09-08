#include <cstdio>
#include <algorithm>
#include <vector>

int N;
std::vector<int> s;

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  s.assign(N, 0);
  for (auto i = 0; i < N; ++i) s[i] = i + 1;

  do
  {
    std::for_each(std::begin(s), std::end(s), [](int const n) { printf("%d ", n); });
    printf("\n");
  } while (std::next_permutation(std::begin(s), std::end(s)));

  return 0;
}
