#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

int T;
int F;
std::map<std::string, int> friends;
std::vector<int> rank;
std::vector<int> parent;

int find(int v)
{
  return (parent[v] == v) ? v : (parent[v] = find(parent[v]));
}

int unite(int v, int w)
{
  v = find(v);
  w = find(w);

  if (v != w) parent[w] = v, rank[v] += rank[w];

  return rank[v];
}

int main(int const argc, char const** argv)
{
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &F);

    friends.clear();
    parent.clear();
    rank.clear();

    parent.resize(F * 2 + 1);
    rank.resize(F * 2 + 1, 1);

    for (auto i = 1; i <= F * 2; ++i) parent[i] = i;

    int index = 0;
    while (F--)
    {
      char a[21], b[21];
      scanf("%s %s", a, b);

      if (!friends[a]) friends[a] = ++index;
      if (!friends[b]) friends[b] = ++index;

      int answer = unite(friends[a], friends[b]);
      printf("%d\n", answer);
    }
  }

  return 0;
}
