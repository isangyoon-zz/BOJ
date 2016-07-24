#include <iostream>
#include <bitset>

int T;
int N;
std::bitset<101> jail;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);

  std::cin >> T;

  for (auto TC = 1; TC <= T; ++TC)
  {
    jail.reset();
    std::cin >> N;

    for (auto i = 2; i <= N; ++i)
    {
      for (auto j = i; j <= N; ++j)
      {
        if (j % i == 0)
        {
          jail.flip(j);
        }
      }
    }

    std::cout << N - jail.count() << std::endl;
  }

	return 0;
}
