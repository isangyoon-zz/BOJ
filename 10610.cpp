#include <iostream>
#include <algorithm>
#include <string>

std::string numbers;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> numbers;

  int sum = 0;
  std::sort(std::begin(numbers), std::end(numbers));
  std::for_each(std::begin(numbers), std::end(numbers), [&](int const number) { sum += number - '0'; });

  std::reverse(std::begin(numbers), std::end(numbers));
  std::cout << ((numbers[numbers.size() - 1] == '0' && (sum % 3 == 0)) ? numbers : "-1") << std::endl;

  return 0;
}
