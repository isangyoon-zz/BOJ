#include <iostream>
#include <string>

int N;
int dp[4001][4001];
std::string s1, s2;

int main(int const argc, char const** argv)
{
  std::cin >> s1 >> s2;

  s1 = "-" + s1;
  s2 = "-" + s2;

  int answer = 0;
  for (unsigned int i = 1; i < s1.length(); ++i)
  {
    for (unsigned int j = 1; j < s2.length(); ++j)
    {
      if (s1.at(i) == s2.at(j))
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;

        if (dp[i][j] > answer) answer = dp[i][j];
      }
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
