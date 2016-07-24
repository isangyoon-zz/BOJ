#include <iostream>

int N;
int dp[1000001];

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    dp[0] = dp[1] = 1;

    for(auto i = 2; i <= N; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }

    std::cout << dp[N] % 15746 << std::endl;

    return 0;
}
