#include <iostream>
#include <algorithm>

int N;
int A[1001];
int asc[1001];
int desc[1001];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);

  std::cin >> N;

  for (auto i = 1; i <= N; ++i)
  {
    std::cin >> A[i];
  }

  for (auto i = 1; i <= N; ++i)
  {
    asc[i] = 1;

    for (auto j = 1; j < i; ++j)
    {
      if (A[i] > A[j] && asc[i] < asc[j] + 1)
      {
        asc[i] = asc[j] + 1;
      }
    }
  }

  for (auto i = N; i > 0; --i)
  {
    desc[i] = 1;

    for (auto j = N; j > i; --j)
    {
      if (A[i] > A[j] && desc[i] < desc[j] + 1)
      {
        desc[i] = desc[j] + 1;
      }
    }
  }

  int answer = 0;
  for (auto i = 1; i <= N; ++i)
  {
    answer = std::max(answer, asc[i] + desc[i] - 1);
  }

  std::cout << answer << std::endl;

	return 0;
}
