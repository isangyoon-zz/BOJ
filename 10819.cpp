#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int N;
std::vector<int> numbers;

unsigned int absolute(int n)
{
  int v = n;
  int const mask = v >> (sizeof(int) * 7);
  unsigned int r = (v + mask) ^ mask;

  return r;
}

template <typename Iterator, typename T = typename std::iterator_traits<Iterator>::value_type>
T calculate(Iterator first, Iterator last, T init)
{
  T sum = init;
  for (auto it = first + 1; it != last; ++it)
  {
    sum += abs(*(it) - *(it - 1));
  }

  return sum;
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  numbers.assign(N, 0);
  for (auto i = 0; i < N; ++i)
  {
    std::cin >> numbers[i];
  }

  std::sort(std::begin(numbers), std::end(numbers));

  int answer = 0;
  do
  {
    int sum = calculate(std::begin(numbers), std::end(numbers), 0);

    answer = (sum > answer) ? sum : answer;
  } while (std::next_permutation(std::begin(numbers), std::end(numbers)));

  std::cout << answer << std::endl;

  return 0;
}
