#include <iostream>
#include <vector>
#include <queue>

int N, M;
std::vector<int> adj[10001];
std::vector<int> answers;

int bfs(int const v)
{
  int count = 1;

  std::vector<bool> visited(N + 1, false);
  std::queue<int> q;

  q.push(v);
  visited[v] = true;

  while (!q.empty())
  {
    const auto current = q.front();
    q.pop();

    for (auto const u : adj[current])
    {
      if (visited[u]) continue;

      visited[u] = true;
      q.push(u);

      ++count;
    }
  }

  return count;
}

int main(int argc, char const** argv)
{
  std::cin >> N >> M;

  while (M--)
  {
    int A, B;

    std::cin >> A >> B;

    adj[B].push_back(A);
  }

  int max = 0;
  for (auto i = 1; i <= N; ++i)
  {
    int count = bfs(i);

    if (count > max)
    {
      answers.clear();
      max = count;

      answers.push_back(i);
    }
    else if(count == max)
    {
      answers.push_back(i);
    }
  }

  for (auto const answer : answers)
  {
    std::cout << answer << " ";
  }
  std::cout << std::endl;

  return 0;
}
