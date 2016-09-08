#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cmath>

const int A = 17;
const int MAX_A = 30;
const int N = 1001;
const double EPS = 1e-9;
const double PI = std::acos(-1.0);

int T;
double X, Y;
int M;

inline double square(double n) { return n * n; }

template <typename T = double>
class point
{
public:
  point() : _x(0.0), _y(0.0) {}
  point(T x, T y) : _x(x), _y(y) {}
  ~point() {}

  T x() const { return _x; }
  T x() { return _x; }

  T y() const { return _y; }
  T y() { return _y; }

  void set(double x, double y) { _x = x, _y = y; }
  std::pair<T, T> get() const { return {_x, _y}; }
  std::pair<T, T> get() { return {_x, _y}; }

  bool check() const
  {
    return (_x > -EPS) && (_x < X + EPS) && (_y > - EPS) && (_y < Y + EPS);
  }

  double distance(point p) const
  {
    return std::sqrt(square(_x - p._x) + square(_y - p._y));
  }

  friend double distance(point lhs, point rhs)
  {
    return std::sqrt(square(lhs._x - rhs._x) + square(lhs._y - rhs._y));
  }

private:
  T _x;
  T _y;
};

point<double> points[N];
point<double> E[MAX_A];
double S[MAX_A];

double anealing(point<double> p)
{
  double min = distance(points[0], p);
  for (int i = 1; i < M; ++i)
  {
    min = std::min(min, distance(points[i], p));
  }

  return min;
}

point<double> solve(double T)
{
  while (T > 1e-3)
  {
    for (int i = 0; i <= A; ++i)
    {
      point<double> e;
      for (int j = 0; j <= MAX_A; ++j)
      {
        double angle = (rand() % 1000 + 1.0) / 1000.0 * 2 * PI;
        e = point<double>(E[i].x() + std::cos(angle) * T, E[i].y() + std::sin(angle) * T);

        if (!e.check()) continue;

        double s = anealing(e);
        if (s > S[i])
        {
          E[i] = e;
          S[i] = s;
        }
      }
    }

    T *= 0.9;
  }

  int index = 0;
  double max = 0.0;
  for (int i = 0; i <= A; ++i)
  {
    if (S[i] > max)
    {
      index = i;
      max = S[i];
    }
  }

  return E[index];
}

int main(int const argc, char const** argv)
{
  scanf("%d", &T);

  while (T--)
  {
    scanf("%lf %lf %d", &X, &Y, &M);

    for (int i = 0; i < M; ++i)
    {
      double x, y;
      scanf("%lf %lf", &x, &y);

      points[i] = point<double>(x, y);
    }

    for (int i = 0; i <= A; ++i)
    {
      E[i] = point<double>((std::rand() % 1000 + 1.0) / 1000.0 * X, (std::rand() % 1000 + 1.0) / 1000.0 * Y);
      S[i] = anealing(E[i]);
    }

    double T = std::max(X, Y) / std::sqrt(1.0 * M);
    point<double> answer = solve(T);

    printf("The safest point is (%.1lf, %.1lf).\n", answer.x(), answer.y());
  }

  return 0;
}
