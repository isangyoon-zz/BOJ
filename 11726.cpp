#include <iostream>

unsigned long long dp[10001];

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);

    dp[0] = dp[1] = 1;

    for(auto i = 2; i <= 1000; ++i)
    {
        dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
    }

    int N;
    std::cin >> N;
    std::cout << dp[N] << std::endl;

    return 0;
}
