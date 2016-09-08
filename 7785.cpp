#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <set>
#include <string>

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::set<std::string, std::greater<std::string>> names;
  while (n--)
  {
    std::string name, status;
    std::cin >> name >> status;

    if (status == "enter") names.insert(name);
    else if (status == "leave") names.erase(names.find(name));
  }

  std::copy(std::begin(names), std::end(names), std::ostream_iterator<std::string>(std::cout, "\n"));

  return 0;
}
