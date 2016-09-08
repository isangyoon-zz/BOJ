#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

int N;
std::vector<bool> prime;
std::vector<int> candidates;

void sieveoferatosthenes(int const n)
{
  prime.assign(n + 1, true);

  prime[0] = prime[1] = false;
  for (auto i = 2; i * i <= n; ++i)
  {
    if (prime[i])
    {
      candidates.push_back(i);

      for (auto j = i * 2; j <= n; j += i)
      {
        prime[j] = false;
      }
    }
  }
}

int main(int const argc, char const** argv)
{
  sieveoferatosthenes(1e6);

  while (scanf("%d", &N) && N)
  {
    for (unsigned int i = 1; i < candidates.size(); ++i)
    {
      if (prime[N - candidates[i]])
      {
        printf("%d = %d + %d\n", N, candidates[i], N - candidates[i]);

        break;
      }
    }
  }

  return 0;
}
