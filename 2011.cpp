#include <iostream>
#include <string>

const int MOD = 1000000;

std::string crypto;
int dp[5001];

int main(int argc, char** argv)
{
  std::getline(std::cin, crypto);

  dp[0] = dp[1] = 1;

  std::size_t length = crypto.size();
  for (unsigned int i = 2; i <= length; ++i)
  {
    int n = crypto.at(i - 1) - '0';
    if(n > 0) dp[i] = dp[i - 1] % MOD;

    n = (crypto.at(i - 2) - '0') * 10 + (crypto.at(i - 1) - '0');
    if(n >= 10 && n <= 26) dp[i] = (dp[i] + dp[i - 2]) % MOD;
  }

  std::cout << dp[length] << std::endl;

  return 0;
}
