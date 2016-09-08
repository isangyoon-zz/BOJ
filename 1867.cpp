#include <iostream>
#include <algorithm>
#include <vector>

int n, k;
bool visited[501];
int matched[501];
std::vector<int> adj[501];

auto dfs(int const v)
{
  if (visited[v]) return false;
  visited[v] = true;

  for (auto const u : adj[v])
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

  std::cin >> n >> k;

  for (auto i = 0; i < k; ++i)
  {
    int r, c;
    std::cin >> r >> c;

    adj[r].push_back(c);
  }

  int answer = 0;
  for (auto i = 1 ; i <= n; ++i)
  {
    std::fill(std::begin(visited), std::end(visited), false);

    if (dfs(i)) ++answer;
  }

  std::cout << answer << std::endl;

  return 0;
}
