#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

const unsigned long long INF = 18446744073709551615ULL;

std::vector<std::pair<int, int>> adj[1001];
int via[1001];
std::vector<unsigned long long> distance;
int N, M;

std::stack<int> paths;

void dijkstra(int start, int end)
{
  std::vector<bool> visited(N + 1, false);

  distance.resize(N + 1, INF);

  auto compare = [](std::pair<int, int> const& lhs, std::pair<int, int> const& rhs) { return lhs.second > rhs.second; };
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> pq(compare);

  via[start] = -1;
  distance[start] = 0;
  pq.push({start, 0});

  while (!pq.empty())
  {
    auto v = pq.top();
    pq.pop();

    if (visited[v.first]) continue;
    visited[v.first] = true;

    std::for_each(std::begin(adj[v.first]), std::end(adj[v.first]), [&](std::pair<int, int> const& u) { if ((!visited[u.first]) && (distance[u.first] > v.second + u.second)) pq.push({u.first, (distance[u.first] = v.second + u.second)}), via[u.first] = v.first; });
  }

  int t = end;
  while (t != -1)
  {
    paths.push(t);

    t = via[t];
  }
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M;

  while (M--)
  {
    int start, end;
    int cost;
    std::cin >> start >> end >> cost;

    adj[start].push_back({end, cost});
  }

  int start, end;
  std::cin >> start >> end;

  dijkstra(start, end);

  std::cout << distance[end] << std::endl;
  std::cout << paths.size() << std::endl;
  while (!paths.empty())
  {
    std::cout << paths.top() << " ";
    paths.pop();
  }
  std::cout << std::endl;

  return 0;
}
