#include <iostream>
#include <algorithm>

int N, M;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M;

  std::cout << ((N == 1) ? 1 : ((N == 2) ? std::min(4, (M + 1) / 2) : ((M >= 7) ? M - 2 : std::min(4, M)))) << std::endl;

  return 0;
}
