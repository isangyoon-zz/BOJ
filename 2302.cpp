#include <iostream>

int N, M;
int dp[41];

int main(int argc, char** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;
  std::cin >> M;

  dp[0] = dp[1] = 1;
  for (auto i = 2; i <= N; ++i)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  int answer = 1;

  int start = 1;
  for (auto i = 1; i <= M; ++i)
  {
    int end;
    std::cin >> end;

    answer *= dp[end - start];
    start = end + 1;
  }
  answer *= dp[N + 1 - start];

  std::cout << answer << std::endl;

  return 0;
}
