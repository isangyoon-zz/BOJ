#include <iostream>

int sum = 0;
int answer = -2147483647;

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for(auto i = 1; i <= N; ++i)
    {
        int num;
        std::cin >> num;

        sum = (sum < 0) ? num : sum + num;
        answer = (answer > sum) ? answer : sum;
    }

    std::cout << answer << std::endl;

    return 0;
}
