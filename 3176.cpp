#include <cstdio>
#include <algorithm>
#include <vector>

struct min_max
{
  int min, max;

  min_max() {}
  min_max(int min, int max) : min(min), max(max) {}

  min_max operator+(min_max const& other) const
  {
    return min_max(std::min(min, other.min), std::max(max, other.max));
  }
};

int N, K;
int parent[100001][17];
int depth[100001];
bool visited[100001];
std::vector<std::pair<int, int>> adj[100001];
min_max answers[100001][17];

void dfs(int const v)
{
  visited[v] = true;

  for (auto u : adj[v])
  {
    if (visited[u.first]) continue;

    parent[u.first][0] = v;
    depth[u.first] = depth[v] + 1;

    answers[u.first][0] = min_max(u.second, u.second);

    for (auto i = 1; i <= 16; ++i)
    {
      answers[u.first][i] = answers[u.first][i - 1] + answers[parent[u.first][i - 1]][i - 1];

      parent[u.first][i] = parent[parent[u.first][i - 1]][i - 1];
    }

    dfs(u.first);
  }
}

min_max answer(1e6, 0);
void lca(int u, int v)
{
  answer = min_max(1e6, 0);

  if (depth[v] > depth[u]) std::swap(u, v);

  for (auto i = 16; i >= 0; --i)
  {
    if (1 << i <= depth[u] - depth[v])
    {
      answer = answer + answers[u][i];
      u = parent[u][i];
    }
  }

  if (u == v) return;

  for (auto i = 16; i >= 0; --i)
  {
    if (parent[u][i] != parent[v][i])
    {
      answer = answer + answers[u][i] + answers[v][i];

      u = parent[u][i];
      v = parent[v][i];
    }
  }

  answer = answer + answers[u][0] + answers[v][0];
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

  scanf("%d", &K);
  for (auto i = 0; i < K; ++i)
  {
    int D, E;
    scanf("%d %d", &D, &E);

    lca(D, E);
    printf("%d %d\n", answer.min, answer.max);
  }

  return 0;
}
