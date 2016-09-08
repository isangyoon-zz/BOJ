#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
std::vector<std::vector<std::pair<int, int>>> adj;
std::vector<int> distance;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M;

  adj.resize(N + 1);
  distance.resize(N + 1, 1 << 30);

  for (auto i = 0; i < M; ++i)
  {
    int A, B, C;
    std::cin >> A >> B >> C;

    adj[A].push_back({ B, C });
  }

  distance[1] = 0;

  bool negative_cycle = false;
  for (auto i = 0; i < N; ++i)
  {
    negative_cycle = false;
    for (auto j = 1; j <= N; ++j)
    {
      std::for_each(std::begin(adj[j]), std::end(adj[j]), [&](auto const u) {
        if (distance[u.first] > distance[j] + u.second)
        {
          negative_cycle = true;
          distance[u.first] = distance[j] + u.second;
        }
      });
    }

    if (!negative_cycle) break;
  }

  if (negative_cycle) std::cout << -1 << std::endl;
  else for (auto i = 2; i <= N; ++i) std::cout << ((distance[i] == (1 << 30)) ? -1 : distance[i]) << std::endl;

  return 0;
}
