#include <iostream>
#include <algorithm>

int a[40001];
int b[40001];

int main(int argc, char** argv)
{
  std::ios::sync_with_stdio(false);
  
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> a[i];
	}

	int answer = 1;

	int j;
	b[1] = a[1];
	for (int i = 2; i <= N; ++i)
	{
		if (a[i] > b[answer])
		{
			b[++answer] = a[i];

			continue;
		}

		j = std::lower_bound(b + 1, b + answer + 1, a[i]) - b;
		b[j] = a[i];
	}

	std::cout << answer << std::endl;

	return 0;
}
