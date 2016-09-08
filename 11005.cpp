#include <iostream>
#include <algorithm>
#include <string>

int N, B;
std::string answer;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N >> B;

  while (N)
  {
    int mod = N % B;

    if (mod < 10) answer += static_cast<char>((mod + '0'));
    else answer += static_cast<char>((mod - 10 + 'A'));

    N /= B;
  }

  std::reverse(std::begin(answer), std::end(answer));
  std::cout << answer << std::endl;

  return 0;
}
