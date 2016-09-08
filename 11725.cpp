#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

int N;
std::vector<int> adj[100001];
int visited[100001];

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  for (auto i = 1; i < N; ++i)
  {
    int A, B;
    scanf("%d %d", &A, &B);

    adj[A].push_back(B);
    adj[B].push_back(A);
  }

  std::queue<int> q;
  q.push(1);

  while (!q.empty())
  {
    int v = q.front();
    q.pop();

    std::for_each(std::begin(adj[v]), std::end(adj[v]), [&](int const u) { if (!visited[u]) visited[u] = v, q.push(u); });
  }

  for (auto i = 2; i <= N; ++i)
  {
    printf("%d\n", visited[i]);
  }

  return 0;
}
