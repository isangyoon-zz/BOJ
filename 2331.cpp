#include <iostream>
#include <cmath>
#include <vector>

int A, P;
std::vector<int> sequence;
int visited[10000001];
int count;

int next_sequence(int a, int p)
{
  int s = 0;
  while (a)
  {
    s += std::pow(a % 10, p);
    a /= 10;
  }

  return s;
}

int length(int a, int p)
{
  if (visited[a] != 0) return visited[a] - 1;
  visited[a] = ++count;

  return length(next_sequence(a, p), p);
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> A >> P;
  std::cout << length(A, P) << std::endl;

  return 0;
}
