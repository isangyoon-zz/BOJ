#include <iostream>

int A, B;
int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> A >> B;

  std::cout << (A + B) << std::endl;

  return 0;
}
