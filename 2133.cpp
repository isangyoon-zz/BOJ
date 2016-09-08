#include <iostream>

int dp[31];

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);

    dp[0] = 1;
    dp[2] = 3;

    int N;
    std::cin >> N;

    for(auto i = 4; i <= N; i += 2)
    {
        dp[i] = 3 * dp[i - 2];

        for(auto j = 4; j <= i; j += 2)
        {
            dp[i] += 2 * dp[i - j];
        }
    }

    std::cout << dp[N] << std::endl;

    return 0;
}
