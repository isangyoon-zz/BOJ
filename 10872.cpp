#include <iostream>

int N;
int factorial[13];

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  factorial[0] = factorial[1] = 1;
  factorial[2] = 2;
  for (int i = 3; i <= 12; ++i)
  {
    factorial[i] = factorial[i - 1] * i;
  }

  std::cout << factorial[N] << std::endl;

  return 0;
}
