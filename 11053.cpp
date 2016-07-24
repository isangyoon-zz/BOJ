#include <iostream>
#include <algorithm>

int a[1001];
int dp[1001];

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for(auto i = 1; i <= N; ++i)
    {
        std::cin >> a[i];
    }

    std::size_t size = 1;
    dp[1] = a[1];

    for(auto i = 2; i <= N; ++i)
    {
        if(a[i] > dp[size])
        {
            dp[++size] = a[i];

            continue;
        }

        auto index = std::lower_bound(dp + 1, dp + size + 1, a[i]) - dp;
        dp[index] = a[i];
    }

    std::cout << size << std::endl;

    return 0;
}
