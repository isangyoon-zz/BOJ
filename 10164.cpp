#include <iostream>

int N, M, K;

long long c(int n, int r)
{
    if(r > n / 2)
    {
        r = n - r;
    }

    long long result = 1;

    for(auto i = 1; i <= r; ++i)
    {
        result *= n - r + i;
        result /= i;
    }

    return result;
}

int main(int argc, char** argv)
{
    std::cin >> N >> M >> K;

    int i = (K) ? ((K - 1) / M) : 0;
    int j = (K) ? ((K - 1) % M) : 0;

    std::cout << c(i + j, j) * c(N + M - i - j - 2, M - j - 1) << std::endl;

    return 0;
}
