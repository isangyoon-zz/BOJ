#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int N;
int zero = 0;
int one = 0;
std::vector<int> positives;
std::vector<int> negatives;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;
  for (auto i = 0; i < N; ++i)
  {
    int number;
    std::cin >> number;

    if (number == 0) ++zero;
    else if (number == 1) ++one;
    else if (number > 1) positives.push_back(number);
    else if (number < 0) negatives.push_back(number);
  }

  std::sort(std::begin(positives), std::end(positives), std::greater<int>());
  std::sort(std::begin(negatives), std::end(negatives));

  std::size_t size = positives.size() % 2;
  if (size & 1) positives.push_back(1);

  size = negatives.size() % 2;
  if (size & 1) negatives.push_back((zero > 0) ? 0 : 1);

  int answer = one;
  for (auto i = 0; i < positives.size(); i += 2) answer += positives[i] * positives[i + 1];
  for (auto i = 0; i < negatives.size(); i += 2) answer += negatives[i] * negatives[i + 1];

  std::cout << answer << std::endl;

  return 0;
}
