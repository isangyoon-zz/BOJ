#include <iostream>
#include <algorithm>

unsigned long long N, M;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N >> M;

  unsigned long long answer1 = 0;
  for (unsigned long long i = 2; i <= N; answer1 += N / i, i *= 2);
  for (unsigned long long i = 2; i <= (N - M); answer1 -= (N - M) / i, i *= 2);
  for (unsigned long long i = 2; i <= M; answer1 -= M / i, i *= 2);

  unsigned long long answer2 = 0;
  for (unsigned long long i = 5; i <= N; answer2 += N / i, i *= 5);
  for (unsigned long long i = 5; i <= (N - M); answer2 -= (N - M) / i, i *= 5);
  for (unsigned long long i = 5; i <= M; answer2 -= M / i, i *= 5);

  std::cout << std::min(answer1, answer2) << std::endl;

  return 0;
}
