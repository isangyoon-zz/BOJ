#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>

int N;
std::vector<std::pair<int, int>> points;
std::set<std::pair<int, int>> set;

inline int square(int const value) { return value * value; };
double distance (std::pair<int, int> const lhs, std::pair<int, int> const rhs)
{
  return static_cast<double>(square(lhs.first - rhs.first) + square(lhs.second - rhs.second));
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;
  points.resize(N);

  for (auto i = 0; i < N; ++i) std::cin >> points[i].first >> points[i].second;

  std::sort(std::begin(points), std::end(points));

  int min = 1e9;
  int r = std::sqrt(min);

  for (auto i = 0, j = 0; i < N; ++i)
  {
    while (points[i].first - points[j].first > r)
    {
      set.erase({points[j].second, points[j].first});

      ++j;
    }

    for (auto it = set.lower_bound({points[i].second - r, -1e9}); it != std::end(set) && it->first <= points[i].second + r; ++it)
    {
      int d = distance({it->second, it->first}, points[i]);

      if (min > d)
      {
        min = d;
        r = std::sqrt(d);
      }
    }

    set.insert({points[i].second, points[i].first});
  }

  std::cout << min << std::endl;

  return 0;
}
