#include <iostream>

int N;
int dp[1000001];

int min(int const& lhs, int const& rhs)
{
    return lhs > rhs ? rhs : lhs;
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    
    std::cin >> N;

    dp[1] = 0;

    for(int i = 2; i <= N; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    std::cout << dp[N] << std::endl;

    return 0;
}
