#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
std::vector<long long> trees;

long long sum(long long const H)
{
  long long total = 0;

  for (auto const tree : trees)
  {
    if (tree >= H)
    {
      total += (tree - H);
    }
  }

  return total;
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N >> M;
  trees.assign(N, 0);

  for (auto i = 0; i < N; ++i)
  {
    std::cin >> trees[i];
  }

  std::sort(std::begin(trees), std::end(trees));

  long long lb = 0;
  long long ub = 2000000000;

  while (lb <= ub)
  {
    long long mid = (lb + ub) / 2;

    if (sum(mid) < M)
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
