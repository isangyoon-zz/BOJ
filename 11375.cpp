#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
std::vector<int> works[1001];
int match[1001];
bool visited[1001];

bool dfs(int v)
{
  if (visited[v]) return false;
  visited[v] = true;

  for (auto const u : works[v])
  {
    if (!match[u] || dfs(match[u]))
    {
      match[u] = v;

      return true;
    }
  }

  return false;
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N >> M;

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

  int answer = 0;
  for (auto i = 1; i <= N; ++i)
  {
    std::fill(std::begin(visited) + 1, std::begin(visited) + N + 1, false);

    if (dfs(i)) ++answer;
  }

  std::cout << answer << std::endl;

  return 0;
}
