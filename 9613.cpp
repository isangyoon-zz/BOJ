#include <iostream>

int T;

int gcd(int a, int b)
{
  while (b != 0)
  {
    int mod = a % b;
    a = b;
    b = mod;
  }

  return a;
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> T;

  while (T--)
  {
    int N;
    std::cin >> N;

    int numbers[101];
    for (int i = 0; i < N; ++i)
    {
      std::cin >> numbers[i];
    }

    int sum = 0;
    for (int i = 0; i < N - 1; ++i)
    {
      for (int j = i + 1; j < N; ++j)
      {
        sum += gcd(numbers[i], numbers[j]);
      }
    }

    std::cout << sum << std::endl;
  }

  return 0;
}
