#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>

int V, E;
std::vector<int> adj[2][100001];
std::stack<int> stack;
int visited[100001];

std::map<int, std::set<int> > answers;

void dfs(int v, std::set<int>& result)
{
  if (visited[v]) return;
  visited[v] = true;

  result.insert(v);

  for (auto const u : adj[1][v])
  {
    dfs(u, result);
  }
}

void fill(int v)
{
  if (visited[v]) return;
  visited[v] = true;

  std::for_each(std::begin(adj[0][v]), std::end(adj[0][v]), [&](int const u) { fill(u); });
  stack.push(v);
}

void scc()
{
  std::fill(std::begin(visited) + 1, std::begin(visited) + V + 1, false);
  for (int i = 1; i <= V; ++i)
  {
    if (!visited[i]) fill(i);
  }

  std::fill(std::begin(visited) + 1, std::begin(visited) + V + 1, false);
  while (!stack.empty())
  {
    int v = stack.top();
    stack.pop();

    if (!visited[v])
    {
      std::set<int> result;
      dfs(v, result);

      answers[*std::begin(result)] = result;
    }
  }
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> V >> E;

  for (int i = 1; i <= E; ++i)
  {
    int A, B;
    std::cin >> A >> B;

    adj[0][A].push_back(B);
    adj[1][B].push_back(A);
  }

  scc();

  std::cout << answers.size() << std::endl;

  for (auto const answer : answers)
  {
    std::for_each(std::begin(answer.second), std::end(answer.second), [](int const node) { std::cout << node << " "; });
    std::cout << "-1\n";
  }

  return 0;
}
