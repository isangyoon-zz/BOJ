#include <iostream>

int bits[20];
int N, S;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N >> S;
  for (auto i = 0; i < N; ++i) std::cin >> bits[i];

  int answer = 0;
  for (auto i = 1; i < (1 << N); ++i)
  {
    int sum = 0;
    for (int j = 0; j < N; ++j)
    {
      if (i & (1 << j)) sum += bits[j];
    }

    if (sum == S) ++answer;
  }

  std::cout << answer << std::endl;

  return 0;
}
