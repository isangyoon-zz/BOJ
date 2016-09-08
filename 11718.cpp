#include <iostream>
#include <string>

std::string line;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  while (std::getline(std::cin, line) && std::cin.good() && !std::cin.eof())
  {
    std::cout << line << std::endl;

    std::cin.clear();
  }

  return 0;
}
