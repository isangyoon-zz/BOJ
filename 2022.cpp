#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

const double EPS = 1e-6;

double x, y, c;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  while (std::cin >> x >> y >> c)
  {
    double lb = 0;
    double ub = std::min(x, y);

    while (std::fabs(ub - lb) > EPS)
    {
      double mid = (lb + ub) / 2.0;

      double h = (std::sqrt(x * x - mid * mid) * std::sqrt(y * y - mid * mid)) / (std::sqrt(x * x - mid * mid) + std::sqrt(y * y - mid * mid));

      if (h > c) lb = mid;
      else ub = mid;
    }

    printf("%.3lf\n", lb);
  }

  return 0;
}
