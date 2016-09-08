#include <iostream>
#include <algorithm>
#include <vector>

int N, K;
std::vector<long long> lines;

long long count(long long mid)
{
  long long total = 0;

  for (auto const line : lines)
  {
    total += (line / mid);
  }

  return total;
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> K >> N;
  lines.assign(K, 0);

  for (auto i = 0; i < K; ++i)
  {
    std::cin >> lines[i];
  }

  std::sort(std::begin(lines), std::end(lines));

  long long lb = 0;
  long long ub = 2147483647;

  while (lb <= ub)
  {
    long long mid = (lb + ub) / 2;

    if (count(mid) < N)
    {
      ub = mid - 1;
    }
    else
    {
      lb = mid + 1;
    }
  }

  std::cout << ub << std::endl;

  return 0;
}
