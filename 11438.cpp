#include <cstdio>
#include <algorithm>
#include <vector>

int N, M;
std::vector<int> adj[100001];

int parents[100001][20];
int in[100001], out[100001];
int count;
int l;

void dfs(int const v, int const parent)
{
  in[v] = ++count;

  parents[v][0] = parent;
  for (auto i = 1; i <= l; ++i) parents[v][i] = parents[parents[v][i - 1]][i - 1];

  std::for_each(std::begin(adj[v]), std::end(adj[v]), [&](int const u) {
    if (parent != u) dfs(u, v);
  });

  out[v] = ++count;
}

bool is_upper(int const v, int const u)
{
  return (in[v] <= in[u]) && (out[v] >= out[u]);
}

int lca(int v, int const u)
{
  if (is_upper(v, u)) return v;
  else if (is_upper(u, v)) return u;

  for (auto i = l; i >= 0; --i)
  {
    if (!is_upper(parents[v][i], u))
    {
      v = parents[v][i];
    }
  }

  return parents[v][0];
}

int main(int const argc, char const** argv)
{
  scanf("%d", &N);
  for (auto i = 1; i <= N - 1; ++i)
  {
    int v, u;
    scanf("%d %d", &v, &u);

    adj[v].push_back(u);
    adj[u].push_back(v);
  }

  for (; (1 << l) <= N; ++l);
  --l;

  dfs(1, 1);

  scanf("%d", &M);
  for (auto i = 1; i <= M; ++i)
  {
    int v, u;
    scanf("%d %d", &v, &u);

    printf("%d\n", lca(v, u));
  }

  return 0;
}
