#include <iostream>

unsigned long long dp[10001];

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);

    int T;
    std::cin >> T;

    dp[0] = 0;
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = 2;

    for(auto i = 5; i <= 100; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    for(auto TC = 1; TC <= T; ++TC)
    {
        int N;
        std::cin >> N;

        std::cout << dp[N] << std::endl;
    }

    return 0;
}
