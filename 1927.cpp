#include <cstdio>
#include <functional>
#include <vector>
#include <queue>

int N;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  for (auto i = 1; i <= N; ++i)
  {
    int x;
    scanf("%d", &x);

    if (x == 0)
    {
      printf("%d\n", (pq.empty()) ? 0 : pq.top());

      if (!pq.empty()) pq.pop();
    }
    else
    {
      pq.push(x);
    }
  }

  return 0;
}
