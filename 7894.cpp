#include <iostream>
#include <cmath>

int T;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> T;

  int m;
  while (T--)
  {
    std::cin >> m;

    double s = 0;
    for (s = 0; m; s += std::log10(m--));

    std::cout << (s ? static_cast<int>(std::ceil(s)) : 1) << std::endl;
  }

  return 0;
}
