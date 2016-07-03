#include <iostream>

int A[1000001];

int main(int argc, char** argv)
{
  std::ios::sync_with_stdio(false);

	int N, K;
	std::cin >> N >> K;

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> A[i];
	}

	int j = N;
	while (A[j--] >= K);
	j++;

	int t = K;
	int answer = 0;
	while (t > 0)
	{
		answer = answer + (t / A[j]);
		t = t % A[j--];
	}
	std::cout << answer << std::endl;


	return 0;
}
