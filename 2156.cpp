#include <iostream>
#include <algorithm>

int N;

int wine[10001];
int dp[10001];

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for(auto i = 1; i <= N; ++i)
    {
        std::cin >> wine[i];
    }

    dp[1] = wine[1];
    dp[2] = dp[1] + wine[2];

    for(auto i = 3; i<= N; ++i)
    {
        dp[i] = dp[i - 1];
        dp[i] = std::max(dp[i], dp[i - 2] + wine[i]);
        dp[i] = std::max(dp[i], dp[i - 3] + wine[i - 1] + wine[i]);
    }

    std::cout << dp[N] << std::endl;

    return 0;
}
