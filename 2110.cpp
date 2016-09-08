#include <iostream>
#include <algorithm>
#include <vector>

int N, C;
std::vector<int> distances;

bool check(int const mid)
{
  int count = 1;
  int last = distances[0];

  std::for_each(std::begin(distances), std::end(distances), [&](int const distance) { if (distance - last >= mid) ++count, last = distance; });

  return (C <= count);
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> C;

  distances.resize(N);
  for (auto i = 0; i < N; ++i) std::cin >> distances[i];

  std::sort(std::begin(distances), std::end(distances));

  int lb = 1;
  int ub = distances[N - 1] - distances[0];
  int answer = 1;
  while (lb <= ub)
  {
    int mid = (lb + ub) / 2;

    if (check(mid))
    {
      answer = std::max(answer, mid);
      lb = mid + 1;
    }
    else
    {
      ub = mid - 1;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
