#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
class fenwick_tree
{
private:
  typedef std::size_t size_type;
  typedef T value_type;

public:
  fenwick_tree(size_type size = 0) : _size(size), _tree(std::vector<value_type>(size)) {}
  fenwick_tree(std::vector<value_type> const& tree) : _size(tree.size()), _tree(tree) {}

  void assign(size_type size, value_type default_value = 0)
  {
    _size = size;
    _tree.assign(size, default_value);
  }

  void resize(size_type size, value_type default_value = 0)
  {
    _size = size;
    _tree.resize(size, default_value);
  }

  void update(int p, value_type value)
  {
    for(; p <= _size; p += (p & (-p))) _tree[p] += value;
  }

  value_type query(int p)
  {
    value_type result = 0;
    for (; p; p -= (p & (-p))) result += _tree[p];

    return result;
  }

  size_type size() const noexcept
  {
    return _size;
  }

private:
  size_type _size;
  std::vector<value_type> _tree;
};

int N, M;
std::vector<std::vector<int>> adj;
std::vector<int> salary;

int level[500001], next_level[500001];
int l;

void dfs(int const u)
{
  level[u] = ++l;
  std::for_each(std::begin(adj[u]), std::end(adj[u]), [](auto const v) { dfs(v); });
  next_level[u] = l;
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> N >> M;

  adj.resize(N + 1);
  salary.resize(N + 1, 0);

  std::cin >> salary[1];
  for (auto i = 2; i <= N; ++i)
  {
    int boss;
    std::cin >> salary[i] >> boss;

    adj[boss].push_back(i);
  }

  dfs(1);

  fenwick_tree<int> tree(N);

  while (M--)
  {
    char c;
    std::cin >> c;

    if (c == 'p')
    {
      int a, x;
      std::cin >> a >> x;

      tree.update(level[a], x);
      tree.update(next_level[a], -x);
    }
    else if (c == 'u')
    {
      int a;
      std::cin >> a;

      std::cout << salary[a] + tree.query(level[a] - 1) << '\n';
    }

    std::cin.clear();
  }

  return 0;
}
