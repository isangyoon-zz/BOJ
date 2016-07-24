#include <iostream>

int N;
int P[1001];
int dp[1001];

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for(auto i = 1; i <= N; ++i)
    {
        std::cin >> P[i];
    }

    for(auto i = 1; i <= N; ++i)
    {
        for(auto j = i; j <= N; ++j)
        {
            dp[j] = dp[j] > dp[j - i] + P[i] ? dp[j] : dp[j - i] + P[i];
        }
    }

    std::cout << dp[N] << std::endl;

    return 0;
}
