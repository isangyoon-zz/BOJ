#include <iostream>
#include <algorithm>
#include <vector>

int N;
std::vector<int> s;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  s.assign(N, 0);
  for (auto i = 0; i < N; ++i)
  {
    std::cin >> s[i];
  }

  bool next = std::next_permutation(std::begin(s), std::end(s));
  if (next)
  {
    std::for_each(std::begin(s), std::end(s), [](int const number) { std::cout << number << " "; });
    std::cout << std::endl;
  }
  else
  {
    std::cout << -1 << std::endl;
  }

  return 0;
}
