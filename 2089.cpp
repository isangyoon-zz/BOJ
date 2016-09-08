#include <iostream>

long long N;

void base(long long const n)
{
  if (n == 0) return;
  else if (n & 1)
  {
    if (n > 0) base(-(n / 2));
    else base((-n + 1) / 2);

    std::cout << 1;
  }
  else
  {
    base(-(n / 2));
    std::cout << 0;
  }
}

int main(int const argc, char const** argv)
{
  std::cin >> N;

  if (N == 0) std::cout << 0;
  else base(N);

  std::cout << std::endl;

  return 0;
}
