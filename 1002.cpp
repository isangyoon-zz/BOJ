#include <iostream>

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);

	int T;
	std::cin >> T;

	for (auto TC = 1; TC <= T; ++TC)
	{
		int x1, y1, r1;
		int x2, y2, r2;
		std::cin >> x1 >> y1 >> r1;
		std::cin >> x2 >> y2 >> r2;

		auto dr1 = (r1 - r2) * (r1 - r2);
		auto dr2 = (r1 + r2) * (r1 + r2);

		auto distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

		if (distance == 0 && dr1 == 0) std::cout << "-1" << std::endl;
		else if (dr1 < distance && distance < dr2) std::cout << "2" << std::endl;
		else if (dr1 == distance || dr2 == distance) std::cout << "1" << std::endl;
		else std::cout << "0" << std::endl;
	}

	return 0;
}
