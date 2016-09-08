#include <cstdio>

const int days[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

int x, y;

int main(int const argc, char const** argv)
{
  scanf("%d %d", &x, &y);

  switch ((days[x - 1] + y) % 7)
  {
    case 0:
      printf("SUN\n");
      break;

    case 1:
      printf("MON\n");
      break;

    case 2:
      printf("TUE\n");
      break;

    case 3:
      printf("WED\n");
      break;

    case 4:
      printf("THU\n");
      break;

    case 5:
      printf("FRI\n");
      break;

    case 6:
      printf("SAT\n");
      break;
  }

  return 0;
}
