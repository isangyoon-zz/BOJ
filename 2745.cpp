#include <iostream>
#include <algorithm>
#include <string>

int B;
std::string N;

int main(int const argc, char const** argv)
{
  std::cin >> N >> B;

  int answer = 0;
  std::for_each(std::begin(N), std::end(N), [&](char const c) {
    if (c >= '0' && c <= '9') answer = answer * B + (c - '0');
    else answer = answer * B + c -'A' + 10;
  });

  std::cout << answer << std::endl;

  return 0;
}
