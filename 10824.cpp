#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

std::string numbers;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::getline(std::cin, numbers);

  int count = 0;
  std::stringstream ss(numbers);
  std::string number;

  std::string AB;
  std::string CD;
  while (std::getline(ss, number, ' '))
  {
    if (count < 2) AB += number;
    else CD += number;

    ++count;
  }

  std::cout << std::stoll(AB) + std::stoll(CD) << std::endl;

  return 0;
}
