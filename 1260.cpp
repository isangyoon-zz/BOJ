#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int N, M;
int V;

std::vector<int> adj[1001];
std::vector<bool> visited;

void dfs(int v)
{
  if (visited[v]) return;
  visited[v] = true;

  std::cout << v << " ";

  for (auto const u : adj[v])
  {
    dfs(u);
  }
}

void bfs(int start)
{
  std::queue<int> q;
  q.push(start);
  visited[start] = true;

  while (!q.empty())
  {
    int v = q.front();
    q.pop();

    std::cout << v << " ";

    for (auto const u : adj[v])
    {
      if (!visited[u])
      {
        q.push(u);
        visited[u] = true;
      }
    }
  }
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N >> M >> V;

  while (M--)
  {
    int from, to;
    std::cin >> from >> to;

    adj[from].push_back(to);
    adj[to].push_back(from);
  }

  for (auto i = 1; i <= N; ++i)
  {
    std::sort(std::begin(adj[i]), std::end(adj[i]));
  }

  visited = std::vector<bool>(N + 1, false);
  dfs(V);
  std::cout << std::endl;

  visited = std::vector<bool>(N + 1, false);
  bfs(V);
  std::cout << std::endl;

  return 0;
}
