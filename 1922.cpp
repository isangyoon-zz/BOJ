#include <iostream>
#include <algorithm>
#include <vector>

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
    v = find(v);
    u = find(u);

    _parent[v] = u;
  }

private:
  std::vector<int> _parent;
  std::vector<int> _rank;
};

struct Edge
{
  int start, end;
  int cost;

  Edge() {};
  Edge(int start, int end, int cost) : start(start), end(end), cost(cost) {};
  ~Edge() {};

  bool operator<(Edge const& edge) const { return edge.cost > cost; }
};

int N, M;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M;

  unionfind p(N);
  std::vector<Edge> graph(M);

  for (auto i = 0; i < M; ++i)
  {
    std::cin >> graph[i].start >> graph[i].end >> graph[i].cost;
  }

  std::sort(std::begin(graph), std::end(graph));

  int answer = 0;
  for (auto i = 0; i < M; ++i)
  {
    Edge edge = graph[i];

    int x = p.find(edge.start);
    int y = p.find(edge.end);

    if (x != y)
    {
      p.unite(edge.start, edge.end);

      answer += edge.cost;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
