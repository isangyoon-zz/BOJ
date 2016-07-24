#include <iostream>
#include <algorithm>

int N;

int box[1001];
int dp[1001];

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for(auto i = 1; i <= N; ++i)
    {
        std::cin >> box[i];
    }

    std::size_t size = 1;
    dp[size] = box[size];

    for(auto i = 2; i <= N; ++i)
    {
        if(box[i] > dp[size])
        {
            dp[++size] = box[i];

            continue;
        }

        auto index = std::lower_bound(dp + 1, dp + size + 1, box[i]) - dp;
        dp[index] = box[i];
    }

    std::cout << size << std::endl;

    return 0;
}
