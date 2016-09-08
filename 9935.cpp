#include <cstdio>
#include <cstring>

char string[1000001];
char bomb[37];

unsigned int top = 0;
char stack[1000001];

int main(int const argc, char const** argv)
{
  scanf("%s", string);
  scanf("%s", bomb);

  std::size_t length = std::strlen(bomb);
  for (unsigned int i = 0, size = std::strlen(string); i <= size; ++i)
  {
    stack[top++] = string[i];

    if (std::strncmp(stack + top - length, bomb, length) == 0) top -= length;
  }

  if (!stack[0]) std::puts("FRULA"); else std::puts(stack);

  return 0;
}
