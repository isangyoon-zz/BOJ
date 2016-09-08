#include <iostream>
#include <queue>
#include <string>

int N;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  std::queue<int> q;
  while (N--)
  {
    std::string command;
    std::cin >> command;

    if (command == "push")
    {
      int argument;
      std::cin >> argument;

      q.push(argument);
    }
    else if (command == "pop")
    {
      std::cout << ((q.empty()) ? -1 : q.front()) << std::endl;
      if (!q.empty()) q.pop();
    }
    else if (command == "size")
    {
      std::cout << q.size() << std::endl;
    }
    else if (command == "empty")
    {
      std::cout << q.empty() << std::endl;
    }
    else if (command == "front")
    {
      std::cout << ((q.empty()) ? -1 : q.front()) << std::endl;
    }
    else if (command == "back")
    {
      std::cout << ((q.empty()) ? -1 : q.back()) << std::endl;
    }
  }

  return 0;
}
