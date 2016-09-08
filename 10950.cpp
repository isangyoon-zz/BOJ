#include <iostream>

int N;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  while (N--)
  {
    int a, b;
    std::cin >> a >> b;

    std::cout << (a + b) << std::endl;
  }

  return 0;
}
