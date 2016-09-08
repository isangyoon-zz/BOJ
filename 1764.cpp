#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <set>

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M;
  std::cin >> N >> M;

  std::set<std::string> a;
  for (auto i = 0; i < N; ++i)
  {
    std::string name;
    std::cin >> name;

    a.insert(name);
  }

  std::set<std::string> b;
  for (auto i = 0; i < M; ++i)
  {
    std::string name;
    std::cin >> name;

    b.insert(name);
  }

  std::set<std::string> c;
  std::set_intersection(std::begin(a), std::end(a), std::begin(b), std::end(b), std::inserter(c, std::begin(c)));

  std::cout << c.size() << std::endl;
  std::copy(std::begin(c), std::end(c), std::ostream_iterator<std::string>(std::cout, "\n"));

  return 0;
}
