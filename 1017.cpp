#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>

int N;
std::vector<int> numbers;
std::vector<bool> primes;

std::vector<int> adj[55];
int matched[55];
bool visited[55]; 

auto make_prime(std::size_t const size)
{
  std::vector<bool> primes(size + 1, true);
  primes[0] = primes[1] = false;

  for (auto p = 2; p <= size; ++p)
  {
    if (!primes[p]) continue;

    int n = 2;
    int multiple = p * n;
    while (multiple <= size)
    {
      primes[multiple] = false;

      ++n;
      multiple = p * n;
    }
  }

  return primes;
}

auto dfs(int const v)
{
  if (visited[v]) return false;
  visited[v] = true;

  for (auto const& u : adj[v])
  {
    if (matched[u] == -1 || dfs(matched[u]))
    {
      matched[u] = v;

      return true;
    }
  }

  return false;
}

auto flow(int const n)
{
  std::fill(std::begin(matched), std::end(matched), -1);

  matched[n] = 0;
  matched[0] = n;

  int match = 0;
  for (auto i = 0; i < N; ++i)
  {
    std::fill(std::begin(visited), std::end(visited), false);
    visited[0] = visited[n] = true;

    if (dfs(i)) ++match;
  }

  return match;
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  primes = make_prime(2000);

  std::cin >> N;
  numbers.resize(N);

  for (auto i = 0; i < N; ++i) std::cin >> numbers[i];

  for (auto i = 0; i < N; ++i)
  {
    for (auto j = 0; j < N; ++j)
    {
      if (i == j) continue;

      if (primes[numbers[i] + numbers[j]]) adj[i].push_back(j);
    }
  }

  std::set<int> answers;
  std::for_each(std::begin(adj[0]), std::end(adj[0]), [&](auto const n) {
    if (flow(n) == (N - 2)) answers.insert(numbers[n]);
  });

  if (answers.empty())
  {
    std::cout << -1 << std::endl;
  }
  else
  {
    std::copy(std::begin(answers), std::end(answers), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
  }

  return 0;
}
