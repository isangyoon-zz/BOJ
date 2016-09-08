#include <iostream>
#include <vector>

int N, M;
std::vector<int> times;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M;
  times.resize(M);

  for (auto i = 0; i < M; ++i) std::cin >> times[i];

  if (M >= N)
  {
    std::cout << N << std::endl;

    return 0;
  }

  long long lb = 0;
  long long ub = 2000000000000000LL;
  while (lb <= ub)
  {
    long long mid = (lb + ub) / 2;

    long long first = 0;
    long long last = M;

    for (auto i = 0; i < M; ++i) last += mid / times[i];

    first = last;

    for (auto i = 0; i < M; ++i)
    {
      if (mid % times[i] == 0) --first;
    }

    ++first;

    if (first > N) ub = mid - 1;
    else if (N > last) lb = mid + 1;
    else
    {
      for (auto i = 0; i < M; ++i)
      {
        if (mid % times[i] == 0)
        {
          if (N == first)
          {
            std::cout << i + 1 << std::endl;

            return 0;
          }

          ++first;
        }
      }
    }
  }

  return 0;
}
