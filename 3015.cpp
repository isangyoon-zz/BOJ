#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  std::vector<int> heights(N, 0);
  for (auto i = 0; i < N; ++i) std::cin >> heights[i];

  long long answer = 0;
  std::stack<std::pair<int, long long>> people;
  for (auto i = 0; i < N; ++i)
  {
    std::pair<int, long long> person = {heights[i], 1};

    while (!people.empty())
    {
      if (person.first >= people.top().first)
      {
        answer += people.top().second;
        if (person.first == people.top().first) person.second += people.top().second;

        people.pop();
      }
      else break;
    }

    if (!people.empty()) ++answer;

    people.push(person);
  }

  std::cout << answer << std::endl;

  return 0;
}
