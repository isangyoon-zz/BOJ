#include <iostream>

int T;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> T;

  while (T--)
  {
    int sum = 0;
    int min = 101;
    for (int i = 1; i <= 7 ; ++i)
    {
      int number;
      std::cin >> number;

      if (!(number & 1))
      {
        min = min > number ? number : min;
        sum += number;
      }
    }

    std::cout << sum << " " << min << std::endl;
  }

  return 0;
}
