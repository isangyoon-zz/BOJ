#include <iostream>

int N, M, K;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M >> K;

  int answer = 0;
  for (;(N >= 2) && (M >= 1) && (N + M >= K + 3); ++answer, N -= 2, --M);

  std::cout << answer << std::endl;

  return 0;
}
