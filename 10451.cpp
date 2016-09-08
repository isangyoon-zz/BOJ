#include <iostream>
#include <vector>

std::vector<int> adj;
std::vector<bool> visited;

void dfs(int v)
{
  if (visited[v]) return;
  visited[v] = true;

  dfs(adj[v]);
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  int T;
  std::cin >> T;

  while (T--)
  {
    int N;
    std::cin >> N;

    adj.assign(N + 1, 0);
    visited.assign(N + 1, false);

    for (auto i = 1; i <= N; ++i)
    {
      std::cin >> adj[i];
    }

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
  }

  return 0;
}
