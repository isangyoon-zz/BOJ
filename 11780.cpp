#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int N, M;
int cities[101][101];
int via[101][101];

void floyd()
{
  for (auto k = 1; k <= N; ++k)
  {
    for (auto i = 1; i <= N; ++i)
    {
      for (auto j = 1; j <= N; ++j)
      {
        if (cities[i][j] > cities[i][k] + cities[k][j])
        {
          cities[i][j] = cities[i][k] + cities[k][j];
          via[i][j] = k;
        }
      }
    }
  }
}

void reconstruct(int v, int u, std::vector<int>& path)
{
  if (via[v][u] == -1)
  {
    path.push_back(v);

    if (v != u) path.push_back(u);
  }
  else
  {
    int w = via[v][u];

    reconstruct(v, w, path);
    path.pop_back();
    reconstruct(w, u, path);
  }
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M;

  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= N; ++j)
    {
      cities[i][j] = (i == j) ? 0 : 100001;
      via[i][j] = -1;
    }
  }

  for (auto i = 0; i < M; ++i)
  {
    int a, b, c;
    std::cin >> a >> b >> c;

    cities[a][b] = std::min(cities[a][b], c);
  }

  floyd();

  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= N; ++j)
    {
      std::cout << ((cities[i][j] == 100001 || i == j) ? 0 : cities[i][j]) << " ";
    }
    std::cout << std::endl;
  }

  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= N; ++j)
    {
      if (i == j)
      {
        std::cout << 0 << std::endl;

        continue;
      }

      std::vector<int> path;
      reconstruct(i, j, path);

      if (path.size() == 0) std::cout << 0 << std::endl;
      else
      {
        std::cout << path.size() << " ";
        std::copy(std::begin(path), std::end(path), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
      }
    }
  }

  return 0;
}
