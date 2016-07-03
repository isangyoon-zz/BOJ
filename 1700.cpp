#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char** argv)
{
  std::ios::sync_with_stdio(false);
  
	std::size_t N;
	int K;
	std::cin >> N >> K;

	std::vector<int> tab(K);
	for (auto i = 0; i < K; ++i)
	{
		std::cin >> tab[i];
	}

	int answer = 0;

	std::vector<bool> plugged(101, false);
	int index = 0;
	int last = tab.front();

	for (auto i = 0; i < K; ++i)
	{
		if (plugged[tab[i]]) continue;

		++index;

		if (N < index)
		{
			std::vector<int> history(101, K);

			int max = -1;
			int victim = -1;

			for (auto j = 0; j < i; ++j)
			{
				if (!plugged[tab[j]]) continue;

				for (auto k = i + 1; k < K; ++k)
				{
					if (tab[j] == tab[k])
					{
						history[tab[j]] = k;

						break;
					}
				}

				if (history[tab[j]] > max)
				{
					max = history[tab[j]];
					victim = tab[j];
				}
			}

			if (victim == -1)
			{
				victim = last;
			}

			++answer;
			plugged[victim] = false;
		}

		last = tab[i];
		plugged[tab[i]] = true;
	}

	std::cout << answer << std::endl;

	return 0;
}
