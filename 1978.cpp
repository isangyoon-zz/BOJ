#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

int N;
std::vector<bool> prime;

void sieveoferatosthenes(int const n)
{
  prime.assign(n + 1, true);

  prime[0] = prime[1] = false;
  for (auto i = 2; i * i <= n; ++i)
  {
    if (prime[i])
    {
      for (auto j = i * 2; j <= n; j += i)
      {
        prime[j] = false;
      }
    }
  }
}

bool isPrime (int i)
{
  return prime[i] == true;
}

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  std::vector<int> numbers(N, 0);

  for (auto i = 0; i < N; ++i)
  {
    scanf("%d", &numbers[i]);
  }

  std::sort(std::begin(numbers), std::end(numbers));
  sieveoferatosthenes(numbers[N - 1]);

  int answer = 0;
  std::for_each(std::begin(numbers), std::end(numbers), [&](int const number) { if (prime[number]) ++answer; });

  printf("%d\n", answer);

  return 0;
}
