#include <iostream>
#include <map>

int N;
std::map<long long, int> cards;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  for (auto i = 0; i < N; ++i)
  {
    long long card;
    std::cin >> card;

    ++cards[card];
  }

  int max = 0;
  long long answer = 0;
  for (auto const card : cards)
  {
    if (card.second > max)
    {
      answer = card.first;
      max = card.second;
    }
    else if (card.second == max && answer > card.first)
    {
      answer = card.first;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
