#include <iostream>
#include <algorithm>
#include <string>
#include <tuple>

int N;
std::tuple<int, int, std::string> people[100001];

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  for (auto i = 0; i < N; ++i)
  {
    int age;
    std::string name;
    std::cin >> age >> name;

    people[i] = std::make_tuple(i + 1, age, name);
  }

  std::sort(std::begin(people), std::begin(people) + N, [](std::tuple<int, int, std::string> const& lhs, std::tuple<int, int, std::string> const& rhs) -> bool { return (std::tie(std::get<1>(lhs), std::get<0>(lhs)) < std::tie(std::get<1>(rhs), std::get<0>(rhs))); });
  std::for_each(std::begin(people), std::begin(people) + N, [&](std::tuple<int, int, std::string> const& person) { std::cout << std::get<1>(person) << " " << std::get<2>(person) << "\n"; });

  return 0;
}
