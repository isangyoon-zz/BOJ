#include <iostream>

int A, B;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> A >> B;

  int sum = 0;
  for (int i = 1, m = 1; i <= B;)
  {
    for (int j = m; j > 0 && i <= B; --j)
    {
      if (i >= A) sum += m;

      ++i;
    }

    ++m;
  }

  std::cout << sum << std::endl;

  return 0;
}
