#include <iostream>

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  int A, B, C;
  std::cin >> A >> B >> C;

  std::cout << ((A + B) % C) << std::endl;
  std::cout << (((A % C) + (B % C)) % C) << std::endl;
  std::cout << ((A * B) % C) << std::endl;
  std::cout << (((A % C) * (B % C)) % C) << std::endl;

  return 0;
}
