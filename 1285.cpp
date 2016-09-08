#include <iostream>

int N;
int coins[50];
int answer = 1e9;

void flip(int const index)
{
  if (index == N)
  {
    int count = 0;
    for (auto i = 1; i < (1 << N); i *= 2)
    {
      int n = 0;
      for (auto j = 0; j < N; ++j)
      {
        if (!(coins[j] & i)) ++n;
      }

      if (N - n > n) count += n;
      else count += (N - n);
    }

    answer = std::min(answer, count);

    return;
  }

  coins[index] = ~coins[index];
  flip(index + 1);

  coins[index] = ~coins[index];
  flip(index + 1);
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  for (int i = 0; i < N; ++i)
  {
    for (int j = (1 << (N - 1)); j > 0; j >>= 1)
    {
      char coin;
      std::cin >> coin;

      if (coin == 'H') coins[i] |= j;
    }
  }

  flip(0);

  std::cout << answer << std::endl;

  return 0;
}
