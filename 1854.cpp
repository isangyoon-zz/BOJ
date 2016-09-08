#include <cstdio>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

int n, m, k;
std::vector<std::vector<std::pair<int, int>>> adj;
std::vector<int> distance;
std::vector<int> count;

int main(int const argc, char const** argv)
{
  scanf("%d %d %d", &n, &m, &k);

  adj.clear();
  distance.clear();
  count.clear();

  adj.resize(n + 1);
  distance.resize(n + 1, 0);
  count.resize(n + 1, 0);

  for (auto i = 0; i < m; ++i)
  {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    adj[a].push_back({b, c});
  }

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
  pq.push({0, 1});

  while (!pq.empty())
  {
    int v = pq.top().second;
    int d = pq.top().first;
    pq.pop();

    if (count[v] == k) continue;
    if (count[v] == k - 1) distance[v] = d;

    std::for_each(std::begin(adj[v]), std::end(adj[v]), [&](auto const u){
      pq.push({d + u.second, u.first});
    });

    ++count[v];
  }

  for (auto i = 1; i <= n; ++i)
  {
    printf("%d\n", (count[i] == k) ? distance[i] : -1);
  }

  return 0;
}
