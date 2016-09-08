#include <iostream>
#include <stack>
#include <string>

int N;

int main(int const argc, char const** argv)
{
  std::cin >> N;

  std::stack<int> stack;
  while (N--)
  {
    std::string command;
    std::cin >> command;

    if (command == "push")
    {
      int argument;
      std::cin >> argument;

      stack.push(argument);
    }
    else if (command == "pop")
    {
      std::cout << ((stack.empty()) ? -1 : stack.top()) << std::endl;
      if (!stack.empty()) stack.pop();
    }
    else if (command == "top")
    {
      std::cout << ((stack.empty()) ? -1 : stack.top()) << std::endl;
    }
    else if (command == "empty")
    {
      std::cout << stack.empty() << std::endl;
    }
    else if (command == "size")
    {
      std::cout << stack.size() << std::endl;
    }
  }

  return 0;
}
