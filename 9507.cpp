#include <iostream>

unsigned long long koong[68];
int t, n;

int main(int argc, char** argv)
{
    std::cin >> t;

    koong[0] = koong[1] = 1;
    koong[2] = 2;
    koong[3] = 4;

    for(auto i = 1; i <= t; ++i)
    {
        std::cin >> n;

        for(auto j = 4; j <= n; ++j)
        {
            if(koong[j]) continue;
            koong[j] = koong[j - 1] + koong[j - 2] + koong[j - 3] + koong[j - 4];
        }

        std::cout << koong[n] << std::endl;
    }

    return 0;
}
