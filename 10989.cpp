#include <cstdio>
#include <map>

int N;
std::map<int, int> numbers;

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  for (auto i = 0; i < N; ++i)
  {
    int number;
    scanf("%d", &number);
    ++numbers[number];
  }

  for (auto const number : numbers)
  {
    for (auto i = 0; i < number.second; ++i)
    {
      printf("%d\n", number.first);
    }
  }

  return 0;
}
