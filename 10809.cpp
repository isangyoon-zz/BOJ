#include <iostream>
#include <algorithm>
#include <string>

std::string word;
int index[26];

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::fill(std::begin(index), std::end(index), -1);

  std::cin >> word;
  for (unsigned int i = 0; i < word.length(); ++i)
  {
    if (index[word[i] - 'a'] != -1) continue;

    index[word[i] - 'a'] = i;
  }

  std::for_each(std::begin(index), std::end(index), [](auto n) { std::cout << n << " "; });
  std::cout << std::endl;

  return 0;
}
