#include <iostream>
#include <algorithm>

int N, M, K;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M >> K;

  if (N >= (M + K - 1) && (M * K) >= N)
  {
    for (auto i = 1; i <= M; ++i)
    {
      for (auto j = std::min(i * K, N - M + i), k = std::min(i * K - K, N - M + i - 1); j > k; --j)
      {
        std::cout << j << " ";
      }
    }
  }
  else std::cout << -1;
  std::cout << std::endl;

  return 0;
}
