#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

const int INF = 1 << 30;

std::vector<std::vector<int>> adj;
int N, E;

std::vector<int> dijkstra(int const start)
{
  std::vector<int> distance(N + 1, INF);
  std::vector<bool> visited(N + 1, false);

  distance[start] = 0;

  for (auto i = 0; i < N - 1; ++i)
  {
    int d = INF + 1;
    int v = -1;
    for (auto i = 1; i <= N; ++i)
    {
      if (!visited[i] && d > distance[i])
      {
        d = distance[i];
        v = i;
      }
    }

    visited[v] = true;

    for (auto i = 1; i <= N; ++i)
    {
      if (distance[i] > distance[v] + adj[v][i])
      {
        distance[i] = distance[v] + adj[v][i];
      }
    }
  }

  return distance;
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> E;

  adj.resize(N + 1, std::vector<int>(N + 1, INF));

  while (E--)
  {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (adj[a][b] > c) adj[a][b] = c;
    if (adj[b][a] > c) adj[b][a] = c;
  }

  int v1, v2, v3;
  v1 = 1;
  std::cin >> v2 >> v3;

  auto d1 = dijkstra(v1);
  auto d2 = dijkstra(v2);
  auto d3 = dijkstra(v3);

  auto dist1 = d1[v2] + d2[v3] + d3[N];
  auto dist2 = d1[v3] + d3[v2] + d2[N];

  auto answer = std::min(dist1, dist2);
  if (answer >= INF) answer = -1;

  std::cout << answer << std::endl;

  return 0;
}
