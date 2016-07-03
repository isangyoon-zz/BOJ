#include <iostream>
#include <functional>
#include <vector>
#include <queue>

std::pair<int, int> score[100001];

int main(int argc, char** argv)
{
  std::ios::sync_with_stdio(false);
  
	int T;
	std::cin >> T;

	for (int TC = 1; TC <= T; ++TC)
	{
		int N;
		std::cin >> N;

		auto compare = [](std::pair<int, int> lhs, std::pair<int, int> rhs) { return lhs.first > rhs.first; };
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, decltype(compare)> heap(compare);

		for (int i = 1; i <= N; ++i)
		{
			std::cin >> score[i].first >> score[i].second;
			heap.push(score[i]);
		}

		int answer = 1;
		int best = heap.top().second;
		heap.pop();

		while (!heap.empty())
		{
			int current = heap.top().second;
			heap.pop();

			if (best > current)
			{
				++answer;
				best = current;
			}
		}

		std::cout << answer << std::endl;
	}

	return 0;
}
