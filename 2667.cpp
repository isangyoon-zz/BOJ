#include <cstdio>
#include <algorithm>
#include <vector>

const int next[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int N;
int map[26][26];
int apt[26][26];
std::vector<int> answers;
int tag;

bool inRange(int const x, int const y)
{
  return ((x >= 1) && (x <= N) && (y >= 1) && (y <= N));
}

int floodfill(int const x, int const y)
{
  int count = 1;
  apt[x][y] = tag;

  for (auto i = 0; i < 4; ++i)
  {
    const int next_x = x + next[i][0];
    const int next_y = y + next[i][1];

    if (inRange(next_x, next_y) && map[next_x][next_y] && !apt[next_x][next_y])
    {
      count += floodfill(next_x, next_y);
    }
  }

  return count;
}

int main(int const argc, char const** argv)
{
  scanf("%d", &N);

  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= N; ++j)
    {
      scanf("%1d", &map[i][j]);
    }
  }

  answers.assign(N * N + 1, 0);
  for (auto i = 1; i <= N; ++i)
  {
    for (auto j = 1; j <= N; ++j)
    {
      if (map[i][j] && !apt[i][j])
      {
        ++tag;
        answers[tag] = floodfill(i, j);
      }
    }
  }

  printf("%d\n", tag);
  std::sort(std::begin(answers) + 1, std::begin(answers) + tag + 1);
  std::for_each(std::begin(answers) + 1, std::begin(answers) + tag + 1, [](int const answer) { printf("%d\n", answer); });

  return 0;
}
