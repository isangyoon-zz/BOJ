#include <iostream>

int T;
int A, B;

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

int lcm(int a, int b)
{
  return ((a * b) / gcd(a, b));
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> T;

  while (T--)
  {
    std::cin >> A >> B;

    std::cout << lcm(A, B) << std::endl;
  }


  return 0;
}
