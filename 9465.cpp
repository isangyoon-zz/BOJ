#include <iostream>
#include <algorithm>

int sticker[2][100001];
int dp[2][100001];

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);

    int T;
    std::cin >> T;

    for(auto TC = 1; TC <= T; ++TC)
    {
        int N;
        std::cin >> N;

        for(auto i = 0; i < 2; ++i)
        {
            for(auto j = 1; j<= N; ++j)
            {
                std::cin >> sticker[i][j];
            }
        }

        for(auto i = 1; i <= N; ++i)
        {
            dp[0][i] = std::max(dp[0][i - 1], dp[1][i - 1] + sticker[0][i]);
            dp[1][i] = std::max(dp[1][i - 1], dp[0][i - 1] + sticker[1][i]);
        }

        std::cout << std::max(dp[0][N], dp[1][N]) << std::endl;
    }

    return 0;
}
