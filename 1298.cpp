#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
std::vector<int> adj[101];;
int match[101];
bool visited[101];

bool dfs(int v)
{
  if (visited[v]) return false;
  visited[v] = true;

  for (auto const u : adj[v])
  {
    if (!match[u] || dfs(match[u]))
    {
      match[u] = v;

      return true;
    }
  }

  return false;
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N >> M;

  for (int i = 1; i <= M; ++i)
  {
    int a, b;
    std::cin >> a >> b;

    adj[a].push_back(b);
  }

  int answer = 0;
  for (int i = 1; i <= N; ++i)
  {
    std::fill(std::begin(visited) + 1, std::begin(visited)+ N + 1, false);

    if (dfs(i)) ++answer;
  }

  std::cout << answer << std::endl;

  return 0;
}
