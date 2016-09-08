#include <iostream>

int dp[100001][3];
int N;

int main(int argc, char** argv)
{
    std::cin >> N;

    dp[1][0] = dp[1][1] = dp[1][2] = 1;

    for(auto i = 2; i <= N; ++i)
    {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 9901;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
    }

    std::cout << (dp[N][0] + dp[N][1] + dp[N][2]) % 9901 << std::endl;

    return 0;
}
