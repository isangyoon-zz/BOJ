#include <iostream>
#include <algorithm>
#include <vector>

int d[1000001];
std::vector<int> a[1000001];
bool visited[1000001];

int answer(int start)
{
	if (visited[start]) return d[start];
	visited[start] = true;

	int max = 0;
	for (auto const& i : a[start])
	{
		max = std::max(max, answer(i));
	}

	return d[start] += max;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);

	int T;
	std::cin >> T;

	for (auto TC = 1; TC <= T; ++TC)
	{
		int N, K;
		std::cin >> N >> K;

		for (auto i = 1; i <= N; ++i)
		{
			std::cin >> d[i];
			a[i].clear();
			visited[i] = false;
		}

		for (auto i = 1; i <= K; ++i)
		{
			int from, to;
			std::cin >> from >> to;

			a[to].push_back(from);
		}

		int W;
		std::cin >> W;

		std::cout << answer(W) << std::endl;
	}

	return 0;
}
