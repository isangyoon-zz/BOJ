#include <iostream>
#include <deque>
#include <string>

int N;
std::deque<int> dq;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  while (N--)
  {
    std::string cmd;
    std::cin >> cmd;

    int value = 0;
    if (cmd == "push_front")
    {
      std::cin >> value;

      dq.push_front(value);
    }
    else if (cmd == "push_back")
    {
      std::cin >> value;

      dq.push_back(value);
    }
    else if (cmd == "pop_front")
    {
      std::cout << ((dq.empty()) ? -1 : dq.front()) << std::endl;

      if (!dq.empty()) dq.pop_front();
    }
    else if (cmd == "pop_back")
    {
      std::cout << ((dq.empty()) ? -1 : dq.back()) << std::endl;

      if (!dq.empty()) dq.pop_back();
    }
    else if (cmd == "size")
    {
      std::cout << dq.size() << std::endl;
    }
    else if (cmd == "empty")
    {
      std::cout << dq.empty() << std::endl;
    }
    else if (cmd == "front")
    {
      std::cout << ((dq.empty()) ? -1 : dq.front()) << std::endl;
    }
    else if (cmd =="back")
    {
      std::cout << ((dq.empty()) ? -1 : dq.back()) << std::endl;
    }
  }

  return 0;
}
