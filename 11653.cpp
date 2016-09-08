#include <iostream>

int N;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  for (auto i = 2; i * i <= N; ++i)
  {
    while (!(N % i))
    {
      std::cout << i << std::endl;

      N /= i;
    }
  }

  if (N > 1) std::cout << N << std::endl;

  return 0;
}
