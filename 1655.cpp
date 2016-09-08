#include <cstdio>
#include <functional>
#include <queue>

int N;

int main(int const argc, char const** argv)
{
  std::priority_queue<int> left;
  std::priority_queue<int, std::vector<int>, std::greater<int>> right;

  scanf("%d", &N);
  while (N--)
  {
    int number;
    scanf("%d", &number);

    if (left.empty() || right.empty())
    {
      left.push(number);
    }
    else
    {
      if (left.top() >= number) left.push(number);
      else if (number >= right.top()) right.push(number);
      else left.push(number);
    }

    while (!(left.size() == right.size() || left.size() == right.size() + 1))
    {
      if (left.size() > right.size())
      {
        right.push(left.top());
        left.pop();
      }
      else
      {
        left.push(right.top());
        right.pop();
      }
    }

    printf("%d\n", left.top());
  }

  return 0;
}
