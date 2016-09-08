#include <iostream>
#include <string>

std::string binary;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> binary;

  std::size_t N = binary.size();

  if (N % 3 == 1)
  {
    std::cout << binary[0];
  }
  else if (N % 3 == 2)
  {
    std::cout << ((binary[0] - '0') * 2) + (binary[1] - '0');
  }

  for (unsigned int i = N % 3; i < N; i += 3)
  {
    std::cout << ((binary[i] - '0') * 4) + ((binary[i + 1] - '0') * 2) + (binary[i + 2] - '0');
  }

  std::cout << std::endl;

  return 0;
}
