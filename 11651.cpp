#include <iostream>
#include <algorithm>
#include <tuple>

class Point
{
public:
  Point() : x(0), y(0) {};
  Point(int x, int y) : x(x), y(y) {};

  bool operator< (Point const& pt) const { return std::tie(y, x) < std::tie(pt.y, pt.x); }

  friend std::ostream& operator<< (std::ostream& os, Point const& p)
  {
    return os << p.x << " " << p.y << "\n";
  }

private:
  int x;
  int y;
};

int N;
Point p[100001];

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  for (auto i = 0; i < N; ++i)
  {
    int x, y;
    std::cin >> x >> y;

    p[i] = Point(x, y);
  }

  std::sort(std::begin(p), std::begin(p) + N);

  for (auto i = 0; i < N; ++i)
  {
    std::cout << p[i];
  }

  return 0;
}
