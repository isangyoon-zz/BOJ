#include <iostream>
#include <algorithm>
#include <string>

struct trie
{
  trie* children[10];
  bool terminal;
  bool hasNext;

  trie() : terminal(false), hasNext(false)
  {
    std::fill(std::begin(children), std::end(children), nullptr);
  }

  ~trie()
  {
    for (auto& child : children)
    {
      if (child) delete child;
    }
  }

  bool insert(char const* word)
  {
    if (*word == 0)
    {
      terminal = true;

      return hasNext;
    }
    else
    {
      int key = *word - '0';

      if (!children[key]) children[key] = new trie();
      hasNext = true;

      return terminal || children[key]->insert(word + 1);
    }
  }
};

int T;
int N;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> T;

  while (T--)
  {
    std::cin >> N;

    trie* numbers = new trie();
    bool consistency = true;

    while (N--)
    {
      std::string number;
      std::cin >> number;

      if (consistency && numbers->insert(number.c_str())) consistency = false;
    }

    std::cout << ((consistency) ? "YES" : "NO") << std::endl;

    delete numbers;
  }

  return 0;
}
