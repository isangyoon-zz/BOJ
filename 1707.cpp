#include <iostream>
#include <vector>

int T;
int V, E;
std::vector<int> adj[200001];
int color[200001];

bool dfs(int v, int c)
{
  color[v] = c;

  for (unsigned int i = 0; i < adj[v].size(); ++i)
  {
    int u = adj[v][i];

    if (color[u] == c) return false;
    if (color[u] == 0 && !dfs(u, (~c) + 1)) return false;
  }

  return true;
}

int main(int argc, char** argv)
{
  std::cin >> T;

  for (auto TC = 1; TC <= T; ++TC)
  {
    std::cin >> V >> E;

    for (auto i = 1; i <= V; ++i)
    {
      adj[i].clear();
      color[i] = 0;
    }

    for (auto i = 1; i <= E; ++i)
    {
      int from, to;
      std::cin >> from >> to;

      adj[from].push_back(to);
      adj[to].push_back(from);
    }

    bool flag = true;
    for (auto i = 1; i <= V && flag; ++i)
    {
      if (color[i] == 0 && !dfs(i, 1)) flag = false;
    }

    std::cout << ((flag) ? "YES" : "NO") << std::endl;
  }

  return 0;
}
