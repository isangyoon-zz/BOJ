#include <iostream>
#include <stack>
#include <string>

std::string str;
std::stack<int> stack;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> str;

  unsigned int answer = 0;
  for (unsigned int i = 0; i < str.length(); ++i)
  {
    if (str[i] == '(')
    {
      stack.push(i);
    }
    else
    {
      if (stack.top() == (i - 1))
      {
        stack.pop();

        answer += static_cast<unsigned int>(stack.size());
      }
      else
      {
        stack.pop();

        ++answer;
      }
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
