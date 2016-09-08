#include <iostream>
#include <stack>
#include <string>

int N;
std::string line;
std::stack<char> left, right;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> line;
  for (auto const c : line)
  {
    left.push(c);
  }

  std::cin >> N;
  while (N--)
  {
    char cmd;
    std::cin >> cmd;

    if (cmd == 'L' && (!left.empty()))
    {
      right.push(left.top());
      left.pop();
    }
    else if (cmd == 'D' && (!right.empty()))
    {
      left.push(right.top());
      right.pop();
    }
    else if (cmd == 'B' && (!left.empty()))
    {
      left.pop();
    }
    else if (cmd == 'P')
    {
      char c;
      std::cin >> c;

      left.push(c);
    }
  }

  while (!left.empty())
  {
    right.push(left.top());
    left.pop();
  }

  while (!right.empty())
  {
    std::cout << right.top();

    right.pop();
  }
  std::cout << std::endl;

  return 0;
}
