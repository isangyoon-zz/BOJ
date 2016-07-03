#include <iostream>
#include <numeric>

int N, M;
int a[101][101];

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

	std::cin >> N >> M;

	for (auto i = 1; i <= N; ++i)
	{
		for (auto j = 1; j <= N; ++j)
		{
			a[i][j] = (i == j) ? 0 : 101;
		}
	}

	for (auto i = 1; i <= M; ++i)
	{
		int A, B;
		std::cin >> A >> B;

		a[A][B] = a[B][A] = 1;
	}

	floyd();

	int index = -1;
	int min = 100000;
	for (auto i = 1; i <= N; ++i)
	{
		int sum = std::accumulate(a[i] + 1, a[i] + N + 1, 0);

		if (min > sum)
		{
			index = i;
			min = sum;
		}
	}

	std::cout << index << std::endl;

	return 0;
}
