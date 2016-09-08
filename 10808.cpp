#include <iostream>
#include <algorithm>
#include <string>

std::string word;
int count[26];

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> word;
  std::for_each(std::begin(word), std::end(word), [&](auto c) { ++count[c - 'a']; });
  std::for_each(std::begin(count), std::end(count), [](auto c) { std::cout << c << " "; });
  std::cout << std::endl;

  return 0;
}
