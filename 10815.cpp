#include <cstdio>
#include <unordered_set>

int N, M;
std::unordered_set<unsigned long long> cards;

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  while (N--)
  {
    int card;
    scanf("%ull", &card);

    cards.insert(card);
  }

  scanf("%d", &M);

  while (M--)
  {
    int card;
    scanf("%ull", &card);

    printf("%d ", cards.find(card) != std::end(cards));
  }
  puts("\n");

  return 0;
}
