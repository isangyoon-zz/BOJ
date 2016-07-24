#include <iostream>
#include <queue>

int N, K;
int adj[100001];

bool inRange(int const x)
{
  return (x >= 0) && (x <= 100000);
}

void bfs(int const start, int const end)
{
  std::queue<int> q;
  q.push(start);

  while (true)
  {
    int current = q.front();
    q.pop();

    if (inRange(current + 1) && !adj[current + 1] && (current + 1) != start)
    {
      q.push(current + 1);
      adj[current + 1] = adj[current] + 1;

      if (current + 1 == end) break;
    }

    if (inRange(current - 1) && !adj[current - 1] && (current - 1) != start)
    {
      q.push(current - 1);
      adj[current - 1] = adj[current] + 1;

      if (current - 1 == end) break;
    }

    if (inRange(current * 2) && !adj[current * 2] && (current * 2) != start)
    {
      q.push(current * 2);
      adj[current * 2] = adj[current] + 1;

      if (current * 2 == end) break;
    }
  }
}

int main(int argc, char** const argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N >> K;

  if (N == K)
  {
    std::cout << "0" << std::endl;
  }
  else
  {
    bfs(N, K);

    std::cout << adj[K] << std::endl;
  }

  return 0;
}
