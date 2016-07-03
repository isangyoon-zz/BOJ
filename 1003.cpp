#include <iostream>

unsigned long long fibonacci(int N, int& cnt, int& cnt2)
{
	if (N == 0)
	{
		++cnt;

		return 0;
	}
	else if (N == 1)
	{
		++cnt2;

		return 1;
	}
	else
	{
		return fibonacci(N - 1, cnt, cnt2) + fibonacci(N - 2, cnt, cnt2);
	}
}

int main(int argc, char** argv)
{
  std::ios::sync_with_stdio(false);
  
	int T;
	std::cin >> T;

	for (int TC = 1; TC <= T; ++TC)
	{
		int N;
		std::cin >> N;

		int answer = 0;
		int answer2 = 0;
		fibonacci(N, answer, answer2);

		std::cout << answer << " " << answer2 << std::endl;
	}

	return 0;
}
