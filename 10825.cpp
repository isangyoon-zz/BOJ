#include <iostream>
#include <algorithm>
#include <string>
#include <tuple>

int N;
std::tuple<std::string, int, int, int> students[100001];

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  for (auto i = 0; i < N; ++i)
  {
    std::string name;
    int korean, english, math;
    std::cin >> name >> korean >> english >> math;

    students[i] = std::make_tuple(name, -korean, english, -math);
  }

  std::sort(std::begin(students), std::begin(students) + N, [](std::tuple<std::string, int, int, int> const& lhs, std::tuple<std::string, int, int, int> const& rhs) -> bool { return (std::tie(std::get<1>(lhs), std::get<2>(lhs), std::get<3>(lhs), std::get<0>(lhs)) < std::tie(std::get<1>(rhs), std::get<2>(rhs), std::get<3>(rhs), std::get<0>(rhs))); });
  std::for_each(std::begin(students), std::begin(students) + N, [&](std::tuple<std::string, int, int, int> const& student) { std::cout << std::get<0>(student) << "\n"; });

  return 0;
}
