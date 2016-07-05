#include <iostream>

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);

	int T;
	std::cin >> T;

	for (auto TC = 1; TC <= T; ++TC)
	{
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;

		int answer = 0;

		int N;
		std::cin >> N;

		for (auto i = 1; i <= N; ++i)
		{
			int cx, cy, r;
			std::cin >> cx >> cy >> r;

			bool c1 = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) < r * r;
			bool c2 = (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy) < r * r;

			answer += c1 ^ c2;
		}

		std::cout << answer << std::endl;
	}

	return 0;
}
