#include <iostream>

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

  int A, B;
  std::cin >> A >> B;

  std::cout << gcd(A, B) << std::endl;
  std::cout << ((A * B) / gcd(A, B)) << std::endl;


  return 0;
}
