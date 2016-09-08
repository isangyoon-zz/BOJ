#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int N, K;
std::vector<std::pair<int, int>> jewelry;
std::multiset<int> bags;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> K;

  jewelry.resize(N);
  for (auto i = 0; i < N; ++i)
  {
    std::cin >> jewelry[i].first >> jewelry[i].second;
  }

  std::sort(std::begin(jewelry), std::end(jewelry), [](std::pair<int, int> const lhs, std::pair<int, int> const rhs) { return lhs.second > rhs.second; });

  for (auto i = 0; i < K; ++i)
  {
    int C;
    std::cin >> C;

    bags.insert(C);
  }

  long long answer = 0;
  for (auto i = 0; i < N; ++i)
  {
    if (bags.lower_bound(jewelry[i].first) != std::end(bags))
    {
      answer += jewelry[i].second;
      bags.erase(bags.lower_bound(jewelry[i].first));
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
