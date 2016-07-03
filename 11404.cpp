#include <iostream>

int N, M;
int a[101][101];

int min(int const& lhs, int const& rhs)
{
	return lhs > rhs ? rhs : lhs;
}

void floyd()
{
	for (int k = 1; k <= N; ++k)
	{
		for (auto i = 1; i <= N; ++i)
		{
			for (auto j = 1; j <= N; ++j)
			{
				if (a[i][j] > a[i][k] + a[k][j])
				{
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);

	std::cin >> N;
	std::cin >> M;

	for (auto i = 1; i <= N; ++i)
	{
		for (auto j = 1; j <= N; ++j)
		{
			if (i == j) a[i][j] = 0;
			else a[i][j] = 100001;
		}
	}

	for (auto i = 1; i <= M; ++i)
	{
		int from, to;
		int cost;

		std::cin >> from >> to >> cost;

		a[from][to] = min(cost, a[from][to]);
	}

	floyd();

	for (auto i = 1; i <= N; ++i)
	{
		for (auto j = 1; j <= N; ++j)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}
