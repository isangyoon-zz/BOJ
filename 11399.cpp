#include <iostream>
#include <algorithm>
#include <numeric>

int cost[1001];
unsigned long long buffer[1001];

int main(int argc, char** argv)
{
  std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> cost[i];
	}

	std::sort(cost, cost + N);

	buffer[0] = cost[0];
	for (int i = 1; i < N; ++i)
	{
		buffer[i] = buffer[i - 1] + cost[i];
	}

	unsigned long long answer = std::accumulate(buffer, buffer + N, 0);
	std::cout << answer << std::endl;

	return 0;
}
