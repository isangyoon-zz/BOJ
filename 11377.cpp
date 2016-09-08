#include <iostream>
#include <algorithm>
#include <vector>

int N, M, K;
std::vector<int> works[1001];
int matched[1001];
bool visited[1001];

auto dfs(int const v)
{
  if (visited[v]) return false;
  visited[v] = true;

  for (auto const& u : works[v])
  {
    if (!matched[u] || dfs(matched[u]))
    {
      matched[u] = v;

      return true;
    }
  }

  return false;
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N >> M >> K;

  for (auto i = 1; i <= N; ++i)
  {
    int count;
    std::cin >> count;

    for (auto j = 1; j <= count; ++j)
    {
      int work;
      std::cin >> work;

      works[i].push_back(work);
    }
  }

  int count = 0;
  int answer = 0;
  for (auto i = 1; i <= N; ++i)
  {
    std::fill(std::begin(visited), std::end(visited), false);

    if (dfs(i)) ++answer;
  }

  for (auto i = 1; i <= N; ++i)
  {
    std::fill(std::begin(visited), std::end(visited), false);

    if (dfs(i)) ++answer, ++count;

    if (count == K) break;
  }

  std::cout << answer << std::endl;

  return 0;
}
