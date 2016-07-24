#include <iostream>
#include <algorithm>

int a[2][4];
int dp[2][4];

int N;

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for(auto i = 1; i <= N; ++i)
    {
        for(auto j = 1; j <= 3; ++j)
        {
            std::cin >> a[0][j];

            a[1][j] = a[0][j];

            a[0][j] += std::min((j == 2) ? std::min(dp[0][1], dp[0][3]) : dp[0][j], dp[0][2]);
            a[1][j] += std::max((j == 2) ? std::max(dp[1][1], dp[1][3]) : dp[1][j], dp[1][2]);
        }

        std::copy(std::begin(a[0]) + 1, std::end(a[0]), std::begin(dp[0]) + 1);
        std::copy(std::begin(a[1]) + 1, std::end(a[1]), std::begin(dp[1]) + 1);
    }

    std::sort(std::begin(dp[0]) + 1, std::end(dp[0]));
    std::sort(std::begin(dp[1]) + 1, std::end(dp[1]));

    std::cout << dp[1][3] << " " << dp[0][1] << std::endl;

    return 0;
}
