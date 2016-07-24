#include <iostream>
#include <vector>
#include <stack>

int N, M;
std::vector<int> adj[32001];
bool visited[32001];
std::stack<int> stack;

void dfs(int v)
{
  visited[v] = true;

  for (auto const u : adj[v])
  {
    if (!visited[u]) dfs(u);
  }

  stack.push(v);
}

void sort()
{
  for (auto i = 1; i <= N; ++i)
  {
    if (!visited[i]) dfs(i);
  }
}

int main(int const argc, char const** argv)
{
  std::cin >> N >> M;

  while(M--)
  {
    int A, B;
    std::cin >> A >> B;

    adj[A].push_back(B);
  }

  for (auto i = 1; i <= N; ++i)
  {
    if (!visited[i]) dfs(i);
  }

  while (!stack.empty())
  {
    std::cout << stack.top() << " ";
    stack.pop();
  }
  std::cout << std::endl;

  return 0;
}
