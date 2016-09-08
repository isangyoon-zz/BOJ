#include <iostream>
#include <algorithm>
#include <vector>

int N;
std::vector<int> adj[1001];
bool visited[1001];
int matched[1001];

struct shark
{
  int size;
  int speed;
  int iq;

  bool operator>= (shark const& other) const
  {
    return size >= other.size && speed >= other.speed && iq >= other.iq;
  }

  bool operator== (shark const& other) const
  {
    return size == other.size && speed == other.speed && iq == other.iq;
  }
};

auto dfs(int const v)
{
  if (visited[v]) return false;
  visited[v] = true;

  for (auto const& u : adj[v])
  {
    if (!matched[u] || dfs(matched[u]))
    {
      matched[u] = v;

      return true;
    }
  }

  return false;
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  std::vector<shark> sharks(N + 1);
  for (auto i = 1; i <= N; ++i)
  {
    std::cin >> sharks[i].size >> sharks[i].speed >> sharks[i].iq;
  }

  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= N; ++j)
    {
      if (i == j) continue;

      if (sharks[i] == sharks[j])
      {
        if (i < j) adj[i].push_back(j);
      }
      else if (sharks[i] >= sharks[j]) adj[i].push_back(j);
    }
  }

  long long answer = 0;
  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= 2; ++j)
    {
      std::fill(std::begin(visited), std::end(visited), false);

      if (dfs(i)) ++answer;
    }
  }

  std::cout << N - answer << std::endl;

  return 0;
}
