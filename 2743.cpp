#include <iostream>
#include <string>

std::string word;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> word;
  std::cout << word.length() << std::endl;

  return 0;
}
