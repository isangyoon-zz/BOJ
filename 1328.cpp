#include <iostream>
#include <cstring>

long long d[101][101][101];

long long solve(int const n, int const left, int const right)
{
  if (n == 1 && left == 1 && right == 1) return 1;
  else if (n == 1 && (left != 1 || right != 1)) return 0;

  long long& cache = d[n][left][right];
  if (cache != -1) return cache;

  return cache = (solve(n - 1, left - 1, right) + solve(n - 1, left, right - 1) + solve(n - 1, left, right) * (n - 2)) % 1000000007;
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  memset(d, -1, sizeof(d));

  int N, L, R;
  std::cin >> N >> L >> R;

  std::cout << solve(N, L, R) << std::endl;

  return 0;
}
