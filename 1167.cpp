#include <cstdio>
#include <algorithm>
#include <vector>

int V;
std::vector<std::pair<int, int> > adj[100001];
std::vector<bool> visited;

std::pair<int, int> dfs(int v)
{
  visited[v] = true;

  std::pair<int, int> answer(v, 0);
  std::for_each(std::begin(adj[v]), std::end(adj[v]), [&](std::pair<int, int> const u) { if (!visited[u.first]) { auto t = dfs(u.first); t.second += u.second; if (t.second > answer.second) { std::swap(t, answer); } } });

  return answer;
}

int main(int const argc, char const** argv)
{
  scanf("%d", &V);

  for (auto i = 1; i <= V; ++i)
  {
    int from;
    scanf("%d", &from);

    int to, cost;
    while (scanf("%d", &to) && (to != -1))
    {
      scanf("%d", &cost);

      adj[from].push_back({ to, cost });
    }
  }

  visited.assign(V + 1, false);
  auto v = dfs(1);

  std::fill(std::begin(visited) + 1, std::begin(visited) + V + 1, false);
  auto u = dfs(v.first);

  printf("%d\n", u.second);

  return 0;
}
