#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

int N, M;
std::vector<int> adj[32001];
int indegree[32001];
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M;

  while (M--)
  {
    int A, B;
    std::cin >> A >> B;

    adj[A].push_back(B);
    ++indegree[B];
  }

  for (auto i = 1; i <= N; ++i)
  {
    if (!indegree[i]) pq.push(i);
  }

  while (!pq.empty())
  {
    int v = pq.top();
    pq.pop();

    std::cout << v << " ";

    std::for_each(std::begin(adj[v]), std::end(adj[v]), [&](int const u) { --indegree[u]; if (!indegree[u]) pq.push(u); });
  }

  std::cout << std::endl;

  return 0;
}
