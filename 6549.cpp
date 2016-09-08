#include <iostream>
#include <algorithm>
#include <stack>

int N;
long long heights[100001];

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  while (std::cin >> N && N)
  {
    for (auto i = 0; i < N; ++i) std::cin >> heights[i];

    long long answer = 0;
    std::stack<long long> stack;
    for (auto i = 0; i < N; ++i)
    {
      while (!stack.empty() && heights[stack.top()] > heights[i])
      {
        long long height = heights[stack.top()];
        stack.pop();

        long long width = i;
        if (!stack.empty()) width = (i - stack.top() - 1);

        answer = std::max(answer, width * height);
      }

      stack.push(i);
    }

    while (!stack.empty())
    {
      long long height = heights[stack.top()];
      stack.pop();

      long long width = N;
      if (!stack.empty()) width = (N - stack.top() - 1);

      answer = std::max(answer, width * height);
    }

    std::cout << answer << std::endl;
  }

  return 0;
}
