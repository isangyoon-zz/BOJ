#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int K;
int N;
std::vector<std::vector<int> > tree;
std::vector<int> buildings;

template <typename Iterator, typename T = typename std::iterator_traits<Iterator>::value_type>
std::vector<T> slice(Iterator first, Iterator last)
{
  std::vector<T> result;
  for (auto it = first; it != last; ++it)
  {
    result.push_back(*it);
  }

  return result;
}

void visit(std::vector<int> building, int const height)
{
  if (building.size() == 1)
  {
    tree[height].push_back(building[0]);

    return;
  }

  unsigned long parent = building.size() / 2L;
  visit(slice(std::begin(building), std::begin(building) + parent), height + 1);
  visit(slice(std::begin(building) + parent + 1, std::end(building)), height + 1);

  tree[height].push_back(building[parent]);
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> K;
  tree.resize(K);

  N = (1 << K) - 1;
  buildings.assign(N, 0);
  for (auto i = 0; i < N; ++i)
  {
    std::cin >> buildings[i];
  }

  visit(buildings, 0);

  for (auto i = 0; i < K; ++i)
  {
    for (auto const node : tree[i])
    {
      std::cout << node << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
