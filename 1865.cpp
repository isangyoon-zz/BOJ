#include <iostream>
#include <algorithm>
#include <vector>

struct edge
{
  int _S, _E, _T;
};

int T;
int N, M, W;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> T;
  while (T--)
  {
    std::cin >> N >> M >> W;

    std::vector<edge> adj(2 * M + W);
    for (auto i = 0; i < M; ++i)
    {
      std::cin >> adj[i]._S >> adj[i]._E >> adj[i]._T;

      adj[i + M] = adj[i];
      std::swap(adj[i + M]._S, adj[i + M]._E);
    }

    for (auto i = 2 * M; i < 2 * M + W; ++i)
    {
      std::cin >> adj[i]._S >> adj[i]._E >> adj[i]._T;
      adj[i]._T *= -1;
    }

    std::vector<int> distance(N + 1, 1 << 30);
    distance[1] = 0;
    M = 2 * M + W;

    bool answer = false;
    for (auto i = 1; i <= N; ++i)
    {
      for (auto j = 0; j < M; ++j)
      {
        int S = adj[j]._S;
        int E = adj[j]._E;
        int T = adj[j]._T;

        if (distance[S] != (1 << 30) && (distance[E] > distance[S] + T))
        {
          distance[E] = distance[S] + T;

          if (i == N) answer = true;
        }
      }
    }

    std::cout << ((answer) ? "YES" : "NO") << std::endl;
  }

  return 0;
}
