#include <iostream>
#include <algorithm>
#include <vector>

int N;
std::vector<std::pair<int, int> > tree[10001];
int answer = 0;

int diameter(int root)
{
  std::pair<int, int> radius = {0, 0};

  for (auto const node : tree[root])
  {
    int cost = diameter(node.first) + node.second;

    if (cost > radius.first)
    {
      std::swap(radius.first, radius.second);

      radius.first = cost;
    }
    else if (cost > radius.second)
    {
      radius.second = cost;
    }
  }

  answer = std::max(answer, radius.first + radius.second);

  return radius.first;
}

int main(int argc, char const** argv)
{
  std::cin >> N;

  for (auto i = 1; i < N; ++i)
  {
    int from, to;
    int cost;

    std::cin >> from >> to >> cost;

    tree[from].push_back({to, cost});
  }

  diameter(1);

  std::cout << answer << std::endl;

  return 0;
}
