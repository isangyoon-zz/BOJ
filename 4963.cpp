#include <cstdio>
#include <algorithm>

const int next[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int w, h;
int map[51][51];

bool inRange(int const x, int const y)
{
  return ((x >= 1) && (x <= h) && (y >= 1) && (y <= w));
}

void floodfill(int const x, int const y)
{
  if (!inRange(x, y) || !map[x][y]) return;
  map[x][y] = 0;

  for (auto i = 0; i < 8; ++i)
  {
    const int next_x = x + next[i][0];
    const int next_y = y + next[i][1];

    floodfill(next_x, next_y);
  }
}

int main(int const argc, char const** argv)
{
  while (scanf("%d %d", &w, &h) && w && h)
  {
    std::fill(&map[0][0], &map[0][0] + sizeof(map) / sizeof(map[0][0]), 0);

    for (auto i = 1; i <= h; ++i)
    {
      for (auto j = 1; j <= w; ++j)
      {
        scanf("%d", &map[i][j]);
      }
    }

    int answer = 0;
    for (auto i = 1; i <= h; ++i)
    {
      for (auto j = 1; j <= w; ++j)
      {
        if (map[i][j]) floodfill(i, j), ++answer;
      }
    }

    printf("%d\n", answer);
  }

  return 0;
}
