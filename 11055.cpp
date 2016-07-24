#include <iostream>
#include <algorithm>

int A[1001];
int dp[1001];
int N;

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
    dp[i] = A[i];

    for (auto j = 1; j < i; ++j)
    {
      if (A[i] > A[j] && dp[j] + A[i] > dp[i])
      {
        dp[i] = dp[j] + A[i];
      }
    }
  }

  int answer = dp[1];
  for (auto i = 2; i <= N; ++i)
  {
    answer = std::max(answer, dp[i]);
  }

  std::cout << answer << std::endl;

  return 0;
}
