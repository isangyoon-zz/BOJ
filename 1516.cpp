#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int N;
std::vector<int> adj[501];
int cost[501];
int d[501];
int indegree[501];

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;

  for (auto i = 1; i <= N; ++i)
  {
    std::cin >> cost[i];

    int from = i;
    int to;
    while (std::cin >> to && (to != -1))
    {
      adj[to].push_back(from);
      ++indegree[from];
    }
  }

  std::queue<int> q;
  for (auto i = 1; i <= N; ++i)
  {
    if (!indegree[i])
    {
      q.push(i);
      d[i] = cost[i];
    }
  }

  while (!q.empty())
  {
    int v = q.front();
    q.pop();

    std::for_each(std::begin(adj[v]), std::end(adj[v]), [&](int const u) {
      --indegree[u];
      d[u] = std::max(d[u], d[v] + cost[u]);

      if (!indegree[u]) q.push(u);
    });
  }

  for (auto i = 1; i <= N; ++i)
  {
    std::cout << d[i] << std::endl;
  }

  return 0;
}
