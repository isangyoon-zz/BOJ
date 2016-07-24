#include <iostream>
#include <algorithm>

int map[1001][1001];
int dp[1001][1001];

int N, M;

int main(int argc, char** argv)
{
    std::cin >> N >> M;

    for(auto i = 1; i <= N; ++i)
    {
        for(auto j = 1; j <= M; ++j)
        {
            std::cin >> map[i][j];
        }
    }

    for(auto i = 1; i <= N; ++i)
    {
        for(auto j = 1; j <= M; ++j)
        {
            dp[i][j] = std::max(dp[i-1][j], std::max(dp[i][j - 1], dp[i - 1][j - 1])) + map[i][j];
        }
    }

    std::cout << dp[N][M] << std::endl;

    return 0;
}
