#include <iostream>

int N;
int a[100][100];

void floyd()
{
	for (int k = 0; k < N; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				a[i][j] |= a[i][k] && a[k][j];
			}
		}
	}
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cin >> a[i][j];
		}
	}

	floyd();

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cout << a[i][j] << " ";
		}

		std::cout << "\n";
	}

	return 0;
}
