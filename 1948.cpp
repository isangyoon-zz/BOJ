#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

int N, M;
std::vector<std::pair<int, int>> adj[10001];
std::vector<int> p[10001];
bool visited[10001];

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M;

  for (auto i = 0; i < M; ++i)
  {
    int start, end, cost;
    std::cin >> start >> end >> cost;

    adj[start].push_back({ end, cost });
  }

  int start, end;
  std::cin >> start >> end;

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> pq;
  pq.push({ 0, start });

  std::vector<int> distance(N + 1, -(1 << 30));
  distance[start] = 0;

  while (!pq.empty())
  {
    auto v = pq.top();
    pq.pop();

    std::for_each(std::begin(adj[v.second]), std::end(adj[v.second]), [&](std::pair<int, int> const u) {
      if (distance[u.first] < v.first + u.second)
      {
        distance[u.first] = v.first + u.second;

        p[u.first].clear();
        p[u.first].push_back(v.second);

        pq.push({ v.first + u.second , u.first });
      }
      else if (distance[u.first] == v.first + u.second)
      {
        p[u.first].push_back(v.second);
      }
    });
  }

  std::cout << distance[end] << std::endl;

  visited[end] = true;

  std::queue<int> q;
  q.push(end);

  int answer = 0;

  while (!q.empty())
  {
    int v = q.front();
    q.pop();

    if (v == start) continue;

    std::for_each(std::begin(p[v]), std::end(p[v]), [&](int const u) {
      ++answer;

      if (!visited[u])
      {
        visited[u] = true;

        q.push(u);
      }
    });
  }

  std::cout << answer << std::endl;

  return 0;
}
