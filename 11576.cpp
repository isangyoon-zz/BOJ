#include <iostream>

int A, B;
int m;

void base(int n, int b)
{
  if (n == 0) return;

  base(n / b, b);
  std::cout << n % b << " ";
}

int main(int const argc, char const** argv)
{
  std::cin >> A >> B;
  std::cin >> m;

  int answer = 0;
  for (auto i = 1; i <= m; ++i)
  {
    int number;
    std::cin >> number;

    answer = answer * A + number;
  }

  base(answer, B);
  std::cout << std::endl;

  return 0;
}
