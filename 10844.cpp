#include <iostream>

int dp[101][10];

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for(auto i = 0; i < 10; ++i)
    {
        dp[1][i] = 1;
    }

    for(auto i = 2; i <= N; ++i)
    {
        dp[i][0] = dp[i - 1][1] % 1000000000;
        for(auto j = 1; j < 9; ++j)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
        dp[i][9] = dp[i - 1][8] % 1000000000;
    }

    int sum = 0;
    for(auto i = 1; i < 10; ++i) sum = (sum + dp[N][i]) % 1000000000;
    std::cout << sum % 1000000000 << std::endl;

    return 0;
}
