#include <iostream>

int N;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  int a, b;
  while (std::cin >> a >> b && std::cin.good())
  {
    std::cout << (a + b) << std::endl;
  }

  return 0;
}
