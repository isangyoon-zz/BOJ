#include <iostream>
#include <algorithm>

int N, M;
int network[101][101];

void floyd()
{
	for (auto k = 1; k <= N; ++k)
	{
		for (auto i = 1; i <= N; ++i)
		{
			for (auto j = 1; j <= N; ++j)
			{
				network[i][j] |= network[i][k] && network[k][j];
			}
		}
	}
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);

	std::cin >> N;
	std::cin >> M;

	for (auto i = 1; i <= M; ++i)
	{
		int from, to;

		std::cin >> from >> to;

		network[from][to] = network[to][from] = 1;
	}

	floyd();

	auto compare = [](int const& value) { return value > 0 && value < 999; };
	auto answer = std::count_if(network[1] + 1, network[1] + N + 1, compare);
	std::cout << answer - 1 << std::endl;

	return 0;
}
