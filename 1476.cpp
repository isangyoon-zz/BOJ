#include <iostream>

int E, S, M;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> E >> S >> M;

  int answer = (6916 * E + 4845 * S + 4200 * M) % 7980;
  std::cout << (answer ? answer : 7980) << std::endl;

  return 0;
}
