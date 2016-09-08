#include <iostream>

int N;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  int answer = 0;
  for (auto i = 5; i <= N; i *= 5) answer += (N / i);

  std::cout << answer << std::endl;

  return 0;
}
