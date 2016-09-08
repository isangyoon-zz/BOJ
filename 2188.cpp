#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
std::vector<int> S[201];
int match[201];
bool visited[201];

bool dfs(int v)
{
  if (visited[v]) return false;
  visited[v] = true;

  for (auto const u : S[v])
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
    int num;
    std::cin >> num;

    for (auto j = 1; j <= num; ++j)
    {
      int si;
      std::cin >> si;

      S[i].push_back(si);
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
