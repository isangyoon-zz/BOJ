#include <iostream>
#include <algorithm>

int N;

int dp[100001];

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for(auto i = 1; i <= N; ++i)
    {
        for(auto j = 1; j * j <= i; ++j)
        {
            dp[i] = (dp[i] > 0) ? std::min(dp[i], dp[i - j * j] + 1) : dp[i - j * j] + 1;
        }
    }

    std::cout << dp[N] << std::endl;

    return 0;
}
