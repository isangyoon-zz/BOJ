#include <cstdio>
#include <algorithm>
#include <vector>
#include <exception>

int N;
int S, E;
int T;

std::vector<std::vector<long long>> answer;
std::vector<std::vector<long long>> adj;

std::vector<std::vector<long long>> operator*(std::vector<std::vector<long long>> const& lhs, std::vector<std::vector<long long>> const& rhs)
{
  std::size_t size = lhs.size();
  std::size_t size2 = rhs.size();

  if (size == size2)
  {
    std::vector<std::vector<long long>> result(size, std::vector<long long>(size, 0));

    for (unsigned int i = 0; i < size; ++i)
    {
      for (unsigned int j = 0; j < size; ++j)
      {
        for (unsigned int k = 0; k < size; ++k)
        {
          result[i][j] += lhs[i][k] * rhs[k][j];
        }

        result[i][j] %= 1000003;
      }
    }

    return result;
  }
  else
  {
    throw std::exception();
  }

  return std::vector<std::vector<long long>>();
}

int main(int const argc, char const** argv)
{
  scanf("%d %d %d %d", &N, &S, &E, &T);

  answer.resize(N * 5, std::vector<long long>(N * 5, 0));
  for (auto i = 0; i < N * 5; ++i) answer[i][i] = 1;

  adj.resize(N * 5, std::vector<long long>(N * 5, 0));
  for (auto i = 0; i < N; ++i)
  {
    for (auto j = 0; j < 4; ++j)
    {
      adj[i * 5 + j][i * 5 + j + 1] = 1;
    }
  }

  for (auto i = 0; i < N; ++i)
  {
    for (auto j = 0; j < N; ++j)
    {
      int path;
      scanf("%1d", &path);

      if (path > 0) adj[i * 5 + path - 1][j * 5] = 1;
    }
  }

  while (T > 0)
  {
    if (T & 1)
    {
      answer = answer * adj;
    }

    adj = adj * adj;
    T >>= 1;
  }

  printf("%lld\n", answer[(S - 1) * 5][(E - 1) * 5]);

  return 0;
}
