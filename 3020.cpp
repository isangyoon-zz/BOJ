#include <iostream>
#include <algorithm>
#include <vector>

int N, H;
std::vector<int> stalactites;
std::vector<int> stalagmites;
std::vector<int> cave;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N >> H;

  cave.push_back(0);
  cave.push_back(H * 2);

  for (int i = 0; i < N; ++i)
  {
    int height;
    std::cin >> height;

    if (i % 2 == 0)
    {
      stalagmites.push_back(height * 2);
      cave.push_back(height * 2);
    }
    else
    {
      stalactites.push_back(height * 2);
      cave.push_back((H - height) * 2);
    }
  }

  std::sort(std::begin(stalactites), std::end(stalactites));
  std::sort(std::begin(stalagmites), std::end(stalagmites));
  std::sort(std::begin(cave), std::end(cave));

  cave.erase(std::unique(std::begin(cave), std::end(cave)), std::end(cave));

  long answer = 1 << 30;
  int count = 0;

  for (int i = 1; i < H * 2; i += 2)
  {
    auto stalactite = std::end(stalactites) - std::upper_bound(std::begin(stalactites), std::end(stalactites), (H * 2) - i);
    auto stalagmite = std::end(stalagmites) - std::upper_bound(std::begin(stalagmites), std::end(stalagmites), i);

    if (answer > (stalactite + stalagmite))
    {
      answer = (stalagmite + stalactite);
      count = 1;
    }
    else if(answer == (stalactite + stalagmite))
    {
      ++count;
    }
  }

  std::cout << answer << " " << count << std::endl;

  return 0;
}
