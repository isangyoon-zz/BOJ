#include <cstdio>
#include <algorithm>
#include <vector>

int N;
std::vector<int> P;

std::size_t lis()
{
  std::vector<int> answer(1, P[0]);

  for (int i = 0; i < N; ++i)
  {
    if (P[i] > answer.back()) answer.push_back(P[i]);
    else *std::lower_bound(std::begin(answer), std::end(answer), P[i]) = P[i];
  }

  return answer.size();
}

int main(int const argc, char const** argv)
{
  while (~scanf("%d", &N))
  {
    P.resize(N);
    for (int i = 0; i < N; ++i) scanf("%d", &P[i]);

    printf("%lu\n", lis());
  }

  return 0;
}
