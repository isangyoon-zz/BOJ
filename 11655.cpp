#include <iostream>
#include <algorithm>
#include <string>

std::string text;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::getline(std::cin, text);

  std::for_each(std::begin(text), std::end(text), [](auto& c) { if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M')) c += 13; else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z')) c -= 13; });
  std::cout << text << std::endl;

  return 0;
}
