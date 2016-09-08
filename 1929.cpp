#include <cstdio>
#include <vector>

int N, M;
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

int main(int const argc, char const** argv)
{
  scanf("%d %d", &M, &N);

  sieveoferatosthenes(N);
  for (auto i = M; i <= N; ++i)
  {
    if (prime[i]) printf("%d\n", i);
  }

  return 0;
}
