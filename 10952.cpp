#include <iostream>

int A, B;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  while (true)
  {
    std::cin >> A >> B;

    if (A == 0 && B == 0) break;

    std::cout << (A + B) << std::endl;
  }

  return 0;
}
