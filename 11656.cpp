#include <iostream>
#include <algorithm>
#include <set>
#include <string>

std::string word;
std::set<std::string> suffix;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> word;

  for (int i = 0; i < word.length(); ++i) suffix.insert(word.substr(i));
  std::for_each(std::begin(suffix), std::end(suffix), [](auto str) { std::cout << str << std::endl; });

  return 0;
}
