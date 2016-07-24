#include <iostream>

int N;
int dp[1001][10];

int main(int argc, char** argv)
{
    std::cin >> N;

    for(auto i = 1; i < 10; ++i)
    {
        dp[1][i] = i + 1;
    }

    if(N > 1)
    {
        for(auto i = 2; i <= N; ++i)
        {
            dp[i][0] = 1;

            for(auto j = 1; j < 10; ++j)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
            }
        }
    }

    std::cout << dp[N][9] << std::endl;


    return 0;
}
