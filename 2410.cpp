#include <iostream>
#include <vector>

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int N;
  std::cin >> N;

  std::vector<long long> d(N + 1, 0);
  std::vector<long long> numbers;
  for (auto i = 1; i <= N; i <<= 1) numbers.push_back(i);

  d[0] = 1;
  for (auto i = 0; i < numbers.size(); ++i)
  {
    for (auto j = numbers[i]; j <= N; ++j)
    {
      d[j] = (d[j] + d[j - numbers[i]]) % 1000000000;
    }
  }

  std::cout << d[N] << std::endl;

  return 0;
}
