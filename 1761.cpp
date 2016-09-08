#include <cstdio>
#include <algorithm>
#include <vector>

int N, M;
int parent[40001][16];
int depth[40001];
int distance[40001];
bool visited[40001];
std::vector<std::pair<int, int>> adj[40001];

void dfs(int const v)
{
  visited[v] = true;

  for (auto u : adj[v])
  {
    if (visited[u.first]) continue;

    parent[u.first][0] = v;
    depth[u.first] = depth[v] + 1;
    distance[u.first] = distance[v] + u.second;

    for (auto i = 1; i <= 15; ++i)
    {
      parent[u.first][i] = parent[parent[u.first][i - 1]][i - 1];
    }

    dfs(u.first);
  }
}

int lca(int u, int v)
{
  if (depth[v] > depth[u]) std::swap(u, v);

  for (auto i = 15; i >= 0; --i)
  {
    if ((1 << i) <= depth[u] - depth[v]) u = parent[u][i];
  }

  if (u == v) return u;

  for (auto i = 15; i >= 0; --i)
  {
    if (parent[u][i] != parent[v][i])
    {
      u = parent[u][i];
      v = parent[v][i];
    }
  }

  return parent[u][0];
}

int main(int const argc, char const** argv)
{
  scanf("%d", &N);
  for (auto i = 0; i < N - 1; ++i)
  {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    adj[A].push_back({ B, C });
    adj[B].push_back({ A, C });
  }

  dfs(1);

  scanf("%d", &M);
  for (auto i = 0; i < M; ++i)
  {
    int A, B;
    scanf("%d %d", &A, &B);

    auto answer = distance[A] + distance[B] - 2 * distance[lca(A, B)];
    printf("%d\n", answer);
  }

  return 0;
}
