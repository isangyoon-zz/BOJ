#include <iostream>
#include <string>

int N;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  while (N--)
  {
    std::string str;
    std::cin >> str;

    int top = 0;
    bool VPS = true;
    for (auto const c : str)
    {
      if (c == '(')
      {
        ++top;
      }
      else if (c == ')')
      {
        if (top == 0)
        {
          VPS = false;

          break;
        }
        else
        {
          --top;
        }
      }
    }

    if (top != 0) VPS = false;

    std::cout << ((VPS) ? "YES" : "NO") << std::endl;
  }

  return 0;
}
