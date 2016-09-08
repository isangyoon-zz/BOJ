#include <iostream>
#include <algorithm>
#include <vector>

int k;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  while (std::cin >> k && k)
  {
    std::vector<int> S(k);
    for (auto i = 0; i < k; ++i) std::cin >> S[i];

    std::vector<int> numbers;
    for (auto i = 0; i < k - 6; ++i) numbers.push_back(0);
    for (auto i = 0; i < 6; ++i) numbers.push_back(1);

    std::vector<std::vector<int> > answers;
    do
    {
      std::vector<int> answer;
      for (auto i = 0; i < k; ++i)
      {
        if (numbers[i]) answer.push_back(S[i]);
      }

      answers.push_back(answer);
    } while (std::next_permutation(std::begin(numbers), std::end(numbers)));

    std::sort(std::begin(answers), std::end(answers));

    for (auto const answer : answers)
    {
      for (auto const n : answer)
      {
        std::cout << n << " ";
      }
      std::cout << std::endl;
    }

    std::cout << std::endl;
  }

  return 0;
}
