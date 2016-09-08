#include <iostream>
#include <algorithm>
#include <vector>

int N;
std::vector<std::pair<int, int> > schedules;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;
  while (N--)
  {
    std::pair<int, int> schedule;
    std::cin >> schedule.first >> schedule.second;

    schedules.push_back(schedule);
  }

  std::sort(std::begin(schedules), std::end(schedules), [](std::pair<int, int> const lhs, std::pair<int, int> const rhs) { return (lhs.second == rhs.second) ? lhs.first < rhs.first : lhs.second < rhs.second; });

  int answer = 0;
  int current = 0;
  std::for_each(std::begin(schedules), std::end(schedules), [&](std::pair<int, int> const schedule) { if (schedule.first >= current) current = schedule.second, ++answer; });

  std::cout << answer << std::endl;

  return 0;
}
