#include <iostream>

int main(int argc, char** argv)
{
  std::ios::sync_with_stdio(false);

	int a, b;

	std::cin >> a >> b;
	std::cout << 2 * (a & ~b) - (a ^ b) << std::endl;

	return 0;
}
