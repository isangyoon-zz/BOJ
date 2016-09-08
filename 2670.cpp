#include <cstdio>

int N;
double m, answer;

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  for (int i = 0; i < N; ++i)
  {
    double n;
    scanf("%lf", &n);

    m = (m < 1) ? n : m * n;
    answer = (m > answer) ? m : answer;
  }

  printf("%.3lf\n", answer);

  return 0;
}
