#include <iostream>

const int IMPOSSIBLE = 2147483646;

int N, K;
int dp[10001];

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);

    std::cin >> N >> K;

    for(auto i = 1; i <= K; ++i)
    {
        dp[i] = IMPOSSIBLE;
    }

    for(auto i = 1; i <= N; ++i)
    {
        int coin;
        std::cin >> coin;

        for(auto j = coin; j <= K; ++j)
        {
            if(dp[j] > dp[j - coin] + 1)
            {
                dp[j] = dp[j - coin] + 1;
            }
        }
    }

    if(dp[K] == IMPOSSIBLE) std::cout << "-1" << std::endl;
    else std::cout << dp[K] << std::endl;

    return 0;
}
