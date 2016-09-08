#include <iostream>
#include <algorithm>
#include <vector>

int N, M;

std::vector<int> adj[1001];
std::vector<bool> visited;

void dfs(int v)
{
  if (visited[v]) return;
  visited[v] = true;

  std::for_each(std::begin(adj[v]), std::end(adj[v]), [](int const u) { dfs(u); });
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N >> M;

  while (M--)
  {
    int from, to;
    std::cin >> from >> to;

    adj[from].push_back(to);
    adj[to].push_back(from);
  }

  visited.assign(N + 1, false);

  int answer = 0;
  for (auto i = 1; i <= N; ++i)
  {
    if (!visited[i])
    {
      ++answer;
      dfs(i);
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
