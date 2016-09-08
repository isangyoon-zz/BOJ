#include <iostream>

int N, M;
int josephus[5001];

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N >> M;

  for (int i = 0; i < N; ++i) josephus[i] = i + 1;

  std::cout << "<";
  for (int i = -1, j = N; j; --j)
  {
    i = (i + M) % j;

    std::cout << josephus[i] << ((j == 1) ? "" : ", ");

    for (int k = i; k < j; ++k) josephus[k] = josephus[k + 1];

    --i;
  }
  std::cout << ">" << std::endl;

  return 0;
}
