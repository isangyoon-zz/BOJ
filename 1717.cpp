#include <cstdio>
#include <vector>

int N, M;

class unionfind
{
public:
  unionfind(int const n) : _parent(n + 1, 0), _rank(n + 1, 1)
  {
    for (auto i = 1; i <= n; ++i) _parent[i] = i;
  }
  ~unionfind() {}

  int find(int v)
  {
    return (_parent[v] == v) ? v : _parent[v] = find(_parent[v]);
  }

  void unite(int v, int u)
  {
    if (_rank[v] >= _rank[u]) _parent[u] = v, _rank[v] += _rank[u];
    else _parent[v] = u, _rank[u] += _rank[v];
  }

private:
  std::vector<int> _parent;
  std::vector<int> _rank;
};

int main(int const argc, char const** argv)
{
  scanf("%d %d", &N, &M);

  unionfind set(N);
  for (auto i = 1; i <= M; ++i)
  {
    int a, b, c;
    scanf("%d %d %d", &c, &a, &b);

    if (c == 0 && a != b)
    {
      int p1 = set.find(b);
      int p2 = set.find(a);

      if (p1 != p2) set.unite(p1, p2);
    }

    if (c == 1)
    {
      if (a == b)
      {
        printf("YES\n");

        continue;
      }

      int p1 = set.find(a);
      int p2 = set.find(b);

      printf((p1 == p2) ? "YES\n" : "NO\n");
    }
  }

  return 0;
}
