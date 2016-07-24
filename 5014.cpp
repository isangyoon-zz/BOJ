#include <iostream>
#include <vector>
#include <queue>

int F, S, G, U, D;
std::vector<int> count(1000001, 1 << 30);

bool inRange(int const x)
{
  return (x > 0) && (x <= F);
}

int bfs(int const start, int const end)
{
  std::queue<int> q;
  q.push(start);
  count[start] = 0;

  while (!q.empty())
  {
    int current = q.front();
    q.pop();

    for (auto i = 1; i <= 2; ++i)
    {
      const int next = (i == 1) ? current + U : current - D;

      if (inRange(next) && count[next] > count[current] + 1)
      {
        q.push(next);
        count[next] = count[current] + 1;
      }
    }
  }

  return count[end];
}

int main(int argc, char const** argv)
{
  std::cin >> F >> S >> G >> U >> D;

  int answer = bfs(S, G);

  if (answer == (1 << 30)) std::cout << "use the stairs" << std::endl;
  else std::cout << answer << std::endl;

  return 0;
}
