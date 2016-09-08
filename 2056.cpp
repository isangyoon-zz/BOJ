#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int N;
std::vector<int> adj[10001];
int cost[10001];
int d[10001];
int indegree[10001];

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;

  for (auto i = 1; i <= N; ++i)
  {
    std::cin >> cost[i];

    int n;
    std::cin >> n;

    while (n--)
    {
      int from = i;
      int to;
      std::cin >> to;

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

  int answer = d[1];
  for (auto i = 2; i <= N; ++i)
  {
    answer = std::max(answer, d[i]);
  }

  std::cout << answer << std::endl;

  return 0;
}
