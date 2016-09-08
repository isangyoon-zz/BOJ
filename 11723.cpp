#include <cstdio>
#include <cstring>

int M;
int S;

int main(int const argc, char const** argv)
{
  scanf("%d", &M);
  while (M--)
  {
    int x;
    char command[1001];
    scanf("%s", command);

    if (!std::strcmp(command, "add"))
    {
      scanf("%d", &x);

      S = (S | (1 << (x - 1)));
    }
    else if (!std::strcmp(command, "remove"))
    {
      scanf("%d", &x);

      S = (S & ~(1 << (x - 1)));
    }
    else if (!std::strcmp(command, "check"))
    {
      scanf("%d", &x);

      int mask = (S & (1 << (x - 1)));
      printf("%d\n", (mask) ? 1 : 0);
    }
    else if (!std::strcmp(command, "toggle"))
    {
      scanf("%d", &x);

      S = (S ^ (1 << (x - 1)));
    }
    else if (!std::strcmp(command, "all"))
    {
      S = (1 << 20) - 1;
    }
    else if (!std::strcmp(command, "empty"))
    {
      S = 0;
    }
  }

  return 0;
}
